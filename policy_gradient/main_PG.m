clear variables
clc
close all
warning 'off'
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../feature_based/
Qlist_all = [];

tic;
settings_file;
lr_a = .001 ;
lr_c = .001;

[I,H] = initIH;
s = get_state(I,H);
[~,nF] = get_features(s,1);
w_c = zeros(1,nF);
w_a = w_c;
counter = 1;
total_rewards = zeros(1,epochs);

[barplot_a, barplot_text_a] = get_bar_weights(w_a,nF,counter);
[barplot_c, barplot_text_c] = get_bar_weights(w_c,nF,counter);

%% 
while counter < 6000
    [I,H] = initIH;
    s = get_state(I,H);
    [a,score_fun] = choose_action_pg(s,w_a);
    term = 0;
    step_number = 1;
    total_reward = 0;
    Qlist = zeros(1,10);
    while term == 0
        
        [s_new,r,~] = stepper(s,a);
        
        total_reward = total_reward +r;
        %Determine Q and F values before and after action a
        Q = get_Q(s,a,w_c);
        F = get_features(s,a);

        %TD target
        [I,H] = state2IH(s);

        if (size(I,1) >= (max_no_of_bars-2) || step_number>7)
            target = r;
            delta = target - Q;
            term = 1;
        else
            [a_new,score_fun_new] = choose_action_pg(s_new,w_a);
            Q_new = get_Q(s_new,a_new,w_c);
            target = r+discount_rate*Q_new;
            delta = target - Q;
            a = a_new;
            s = s_new;
            score_fun = score_fun_new;
        end

        %Weight updates
        w_a = w_a + lr_a * score_fun * Q;
        w_c = w_c + lr_c * delta * F;

        step_number = step_number+1;
        Qlist(step_number) = Q;
    end
    counter = counter+1;
    total_rewards(counter) = total_reward;
    barplot_a.YData = w_a;
    barplot_text_a.String = strcat('Epochs: ',int2str(counter));
    barplot_c.YData = w_c;
    barplot_text_c.String = strcat('Epochs: ',int2str(counter));
    drawnow
    Qlist_all = [Qlist_all;Qlist];
    if mod(counter,10+1)==0
        disp('COUNTER')
        disp(counter)
        disp(mean(total_rewards(counter-9:counter)))
    end
    
end
total_rewards = total_rewards(1:counter);

toc
