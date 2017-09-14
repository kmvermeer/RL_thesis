close all
tstart = tic;
settings_file;
counter = 0;
[I,H] = initIH;
initial_reward = get_reward(I,H,negative_reward);
s = get_state(I,H);
[~,nF] = get_features(s,1);
w = zeros(1,nF);
[barplot, barplot_text] = get_bar_weights(w,nF,counter);
total_reward_list = zeros(1,epochs);
wlist = w;    
rlist = [0];
Qlist = [0];
deltalist = [0];
alist_all = [];
[layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,...
    hidden_multiplier,negative_reward,expl_factor] = get_NN_settings(settings);

%% Initialize basic 4bar starting point mechanism
while counter < epochs
    
    tic
    TDlist = '';
    linklist = [];
    a_list = [];
    [I,H] = build_mech(H0,TDlist,linklist);
    s = get_state(I,H);
    [Q,a] = choose_action(s,w,counter,a_list);
    term = 0;
    total_reward = initial_reward;
    %% Perform SARSA
    while term == 0
        step_number = 1;
        total_reward = 0;
        a_list = [a_list a];
        
        [Q,F] = get_Q(s,a,w);
        
        if (size(I,1) >= (max_no_of_bars-2) || step_number>7)
            target = r;
            term = 1;
        else
            [s_new,r,feasible_design] = stepper(s,a,negative_reward);
            [Q_new,a_new] = choose_action(s_new,w,counter,a_list,expl_factor);
            target = r+discount_rate*Q_new;
            [I,H] = state2IH(s_new);
            s = s_new;
            a = a_new;

        end
        
        delta = target - Q;
        update = lr*delta*F;
        w = w+update;
        
        wlist= [wlist;w];
        
        total_reward = r + total_reward;
        deltalist=[deltalist;delta];
        Qlist = [Qlist;Q];
        step_number = 1 + step_number;
    end
    alist_all = [alist_all;a_list(:)];
    counter = counter+1;
    total_reward_list(counter) = total_reward;
    barplot.YData = w;
    barplot_text.String = strcat('Epochs: ',int2str(counter));
    drawnow
    if mod(counter,10)==0
        disp('COUNTER')
        disp(counter)
        disp(total_reward)
    end
end

disp('Finished all epochs')
load train
sound(y,2*Fs)
toc(tstart)


