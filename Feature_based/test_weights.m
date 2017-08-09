settings_file;

%% Initialize basic 4bar starting point mechanism
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
%     [Q,a] = choose_action(s,w,'deterministic',[],0);
    [Q,a] = choose_action_NN(s,weights,a_list,'deterministic',layer_settings);
    Qlist(i) = Q;
%     if Q == 0
%         keyboard
%     end
    [s_new,r] = stepper(s,a);
    r
    total_reward = total_reward+r;
    G = discount_rate*G+r;
    s = s_new;
    a_list(i) = a;
end
[I,H] = state2IH(s);
score = get_reward(I,H,true)
% animateIH(I,H);