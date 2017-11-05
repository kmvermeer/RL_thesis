
close all

tstart = tic;
settings_file;
[layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,...
    hidden_multiplier,negative_reward,expl_factor,max_no_of_hinges,...
          max_no_of_bars,nA] = get_NN_settings(settings_struct);
counter = 1;
[I,H] = initIH(max_no_of_hinges,max_no_of_bars);
s = get_state(I,H,max_no_of_hinges,max_no_of_bars);
initial_reward = get_reward(I,H,settings_struct);
[~,nF] = get_features(s,1,max_no_of_hinges,max_no_of_bars);
Qlist_all = [];
alist_all = [];
total_reward_list = zeros(1,epochs);
error_list = [];
random_bool_list = [];
acounter = zeros(1,nA);
max_stepcount = max_no_of_hinges - 4;
length_a_list = max_stepcount;
length_q_list = length_a_list;

%% Init NN
    
nIn = nF;
nOut = 1;
nHidden = round(hidden_multiplier*nF);
layer_settings.sizes = [nIn,nHidden,nOut];

for l = 1:length(layer_settings.sizes)-1
    weight_factor = sqrt(6)/(sqrt(layer_settings.sizes(l)+layer_settings.sizes(l+1)+2));
    weights{l} = weight_factor*(2*rand(layer_settings.sizes(l)+1,layer_settings.sizes(l+1))-1);
end
grad = cellfun(@(x) x*0,weights,'uni',false);
MS_grad = cellfun(@(x) x*0,weights,'uni',false);

%% Initialize basic 4bar starting point mechanism
while counter < epochs
    
    TDlist = '';
    linklist = [];
    a_list = zeros(1,length_a_list);
    [I,H] = build_mech(H0,TDlist,linklist);
    s = get_state(I,H,max_no_of_hinges,max_no_of_bars);
    [Q,a,random_bool] = choose_action_NN(s,weights,a_list,counter,...
                        settings_struct,max_no_of_hinges,max_no_of_bars);
    term = 0;
    Qlist = zeros(1,length_q_list);
    step_number = 1;
    total_reward = initial_reward;
    a_list(step_number) = a;

    %% Perform SARSA
    while term == 0
        tic
        random_bool_list = [random_bool_list;random_bool];
        if a>0
            acounter(a) = acounter(a)+1;
        end
        [Q,F] = get_Q_NN(s,a,weights,layer_settings,max_no_of_hinges,max_no_of_bars);
        
        [s_new,r,feasible_design] = stepper(s,a,settings_struct);
        [I,H] = state2IH(s_new,max_no_of_hinges,max_no_of_bars);
        
        if (size(I,1) > (max_no_of_bars-2) || step_number >= (length_q_list-1)) 
            %perform update alternative
            target = r;
            delta = target-Q;            
            term = 1;

        else
            [Q_new,a_new,random_bool] = choose_action_NN(s_new,weights,...
                                        a_list,counter,settings_struct);
            target = r+discount_rate*Q_new;
            s = s_new;
            a = a_new;
            
        end
        [new_weights,grad,MS_grad,output,error] = train_NN (weights, F, target, ...
                                                    layer_settings, lr, decay_m,...
                                                    decay_RMS, grad, MS_grad, counter,...
                                                    NN_trainer_style);
        weights = new_weights;
      
        total_reward = r + total_reward;
        error_list = [error_list;error];
        Qlist(step_number) = Q;
        step_number = step_number+1;
        a_list(step_number) = a;
        if a == 0
            a_list(step_number) = -1;
        end

    end
    total_reward_list(counter) = total_reward;
    counter = counter+1;  
    Qlist(step_number) = Q_new;
    Qlist_all = [Qlist_all;Qlist];
    alist_all = [alist_all;a_list];
%      barplot.YData = weights.W2(1:nHidden);
%      barplot_text.String = strcat('Epochs: ',int2str(counter));
%      drawnow
    if mod(counter,10+1)==0
        disp('COUNTER')
        disp(counter)
        disp(mean(error_list(end-9:end)))
        disp(total_reward)
        disp(a_list)
    end
end

disp('Finished all epochs')
% load train
% sound(y,2*Fs)
run_time = toc(tstart);



