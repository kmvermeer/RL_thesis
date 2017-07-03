
settings_file;

%% Initialize basic 4bar starting point mechanism
TDlist = '';
linklist = [];
a_list = [];
[I,H] = build_mech(H0,TDlist,linklist);
s = get_state(I,H);
a_list = [];

for i = 1:10
    [I,H] = state2IH(s);
    get_reward(I,H)
    [Q,a] = choose_action(s,w,9999999,[]);
    [s_new,~] = stepper(s,a);
    s = s_new;
    a_list = [a_list a];
end
[I,H] = state2IH(s);
score = get_reward(I,H,true)
animateIH(I,H);