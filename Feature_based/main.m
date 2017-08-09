clear all
clc
close all
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/evaluation_using_FEM/
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/basic_RL_Hod/
tstart = tic;
settings_file;
counter = 0;
[I,H] = initIH;
s = get_state(I,H);
[~,nF] = get_features(s,1);
w = zeros(1,nF);
[barplot, barplot_text] = get_bar_weights(w,nF,counter);
wlist = w;    
rlist = [0];
deltalist = [0];
Qlist_all = [];
alist_all = [];
acounter = zeros(1,nA);
%% Initialize basic 4bar starting point mechanism
while counter < epochs
    
    tic
    TDlist = '';
    linklist = [];
    a_list = zeros(1,10);
    [I,H] = build_mech(H0,TDlist,linklist);
    s = get_state(I,H);
    [Q,a] = choose_action(s,w,counter,a_list,acounter);
    term = 0;
    Qlist = zeros(1,10);
    step_number = 1;
    %% Perform SARSA
    while term == 0
        
        a_list(step_number) = a;
        acounter(a) = acounter(a)+1;
        [Q,F] = get_Q(s,a,w);
        
        [s_new,r,feasible_design] = stepper(s,a);
        [I,H] = state2IH(s_new);
        
        if (size(I,1) >= (max_no_of_bars-2) || step_number>7)
            %perform update alternative
            target = r;
            delta = target-Q;
            update = learning_rate*delta*F;
            w = w+update;
            term = 1;

        else?