settings_file;

%% Initialize basic 4bar starting point mechanism
[layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,...
    hidden_multiplier,negative_reward,expl_factor,max_no_of_hinges,...
          max_no_of_bars,nA] = get_NN_settings(settings_struct);
TDlist = '';
linklist = [];
a_list = [];
[I,H] = build_mech(H0,TDlist,linklist);
s = get_state(I,H,max_no_of_hinges,max_no_of_bars);
a_list = zeros(1,10);
total_reward = get_reward(I,H);
Qlist = zeros(1,10);
G = 0;
no_of_steps = max_no_of_hinges-4;
for i = 1:no_of_steps
    [I,H] = state2IH(s,max_no_of_hinges,max_no_of_bars);
%     [Q,a] = choose_action(s,w,counter,a_list,'deterministic') %LINEAR
    [Q,a] = choose_action_NN(s,weights,a_list,'deterministic',settings_struct);  %NN
    Qlist(i) = Q;

    [s_new,r] = stepper(s,a,negative_reward,max_no_of_hinges,max_no_of_bars);
    r
    total_reward = total_reward+r;
    G = discount_rate*G+r;
    s = s_new;
    a_list(i) = a;
    if i == 3
        F = get_features(s,a,max_no_of_hinges,max_no_of_bars);
    end
end
[I,H] = state2IH(s,max_no_of_hinges,max_no_of_bars);
score = get_reward(I,H,negative_reward,true)
% animateIH(I,H);

total_reward
disp(alist_all(end-5:end,:))
disp(a_list)