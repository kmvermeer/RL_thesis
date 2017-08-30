clear variables
clc
close all
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/


tstart = tic;
settings_file;
counter = 1;
[I,H] = initIH;
s = get_state(I,H);
[~,nF] = get_features(s,1);
rlist = [0];
deltalist = [0];
Qlist_all = [];
alist_all = [];
delta_hidden_list = [];
delta_list = [];
error_list = [];
random_bool_list = [];
acounter = zeros(1,nA);
mean_hidden_errors = zeros(1,epochs*6);
%% Init NN
nIn = nF;
nHidden = round(4*nF);
nOut = 1;

layer_settings.sizes = [nIn,nHidden,nOut];
layer_settings.styles = {'Sigmoid','linear'};
lr = 0.3;
decay_m = 0.9; 
decay_RMS = 0.99;

for l = 1:length(layer_settings.sizes)-1
    weight_factor = sqrt(6)/(sqrt(layer_settings.sizes(l)+layer_settings.sizes(l+1)+2));
    weights{l} = weight_factor*(2*rand(layer_settings.sizes(l)+1,layer_settings.sizes(l+1))-1);
end
grad = cellfun(@(x) x*0,weights,'uni',false);
MS_grad = cellfun(@(x) x*0,weights,'uni',false);

%% Initialize basic 4bar starting point mechanism
while counter < epochs
    
    tic
    TDlist = '';
    linklist = [];
    a_list = zeros(1,10);
    [I,H] = build_mech(H0,TDlist,linklist);
    s = get_state(I,H);
    [Q,a,random_bool] = choose_action_NN(s,weights,a_list,counter,layer_settings);
    term = 0;
    Qlist = zeros(1,10);
    step_number = 1;
    %% Perform SARSA
    while term == 0
        total_reward = 0;
        random_bool_list = [random_bool_list;random_bool];
        a_list(step_number) = a;
        acounter(a) = acounter(a)+1;
        [Q,F] = get_Q_NN(s,a,weights,layer_settings);
        
        [s_new,r,feasible_design] = stepper(s,a);
        [I,H] = state2IH(s_new);
        
        if (size(I,1) >= (max_no_of_bars-2) || step_number>7)
            %perform update alternative
            target = r;
            delta = target-Q;
            [new_weights,grad,MS_grad,output,error] = train_NN (weights, F, target, ...
                                                    layer_settings, lr, decay_m,...
                                                    decay_RMS, grad, MS_grad, counter,...
                                                    'Adams');
            weights = new_weights;
            term = 1;

        else
            [Q_new,a_new,random_bool] = choose_action_NN(s_new,weights,a_list,counter,layer_settings);
            target = r+discount_rate*Q_new;
            [new_weights,grad,MS_grad,output,error] = train_NN (weights, F, target, ...
                                                    layer_settings, lr, decay_m,...
                                                    decay_RMS, grad, MS_grad, counter,...
                                                    'Adams');
            weights = new_weights;
            s = s_new;
            a = a_new;
            
        end
        total_reward = r + total_reward;
        error_list = [error_list;error];
        rlist = [rlist;r];
        Qlist(step_number) = Q;
        step_number = step_number+1;
        counter = counter+1;
    end
        
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
load train
sound(y,2*Fs)
toc(tstart)




