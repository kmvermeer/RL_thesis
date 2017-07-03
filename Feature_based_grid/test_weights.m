settings_file;

%% Initialize basic 4bar starting point mechanism
TDlist = '';
linklist = [];
a_list = [];
[I,H,M] = build_mech_gridworld(H0,TDlist,linklist,gridxy);
s = get_state(I,H);
a_list = [];


for i = 1:3
    [Q,a] = choose_action(s,w,counter);
    [s_new,~] = stepper(s,a);
    s = s_new;
    a_list = [a_list a];
end
[I,H] = state2IH(s);
score = get_reward(I,H)
animateIH(I,H);