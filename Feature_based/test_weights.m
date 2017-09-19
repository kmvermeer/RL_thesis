settings_file;

%% Initialize basic 4bar starting point mechanism
[layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,...
    hidden_multiplier,negative_reward,expl_factor] = get_NN_settings(settings);
TDlist = '';
linklist = [];
a_list = [];
[I,H] = build_mech(H0,TDlist,linklist);
s = get_state(I,H);
a_list = zeros(1,10);
total_reward = get_reward(I,H);
Qlist = zeros(1,10);
G = 0;
for i = 1:4
    [I,H] = state2IH(s);
%     [Q,a] = choose_action(s,w,counter,a_list,'deterministic') %LINEAR
    [Q,a] = choose_action_NN(s,weights,a_list,'deterministic',layer_settings,expl_factor);  %NN
    Qlist(i) = Q;

    [s_new,r] = stepper(s,a,negative_reward);
    r
    total_reward = total_reward+r;
    G = discount_rate*G+r;
    s = s_new;
    a_list(i) = a;
    if i == 3
        F = get_features(s,a);
    end
end
[I,H] = state2IH(s);
score = get_reward(I,H,negative_reward,true)
% animateIH(I,H);

total_reward
disp(alist_all(end-5:end,:))
disp(a_list)