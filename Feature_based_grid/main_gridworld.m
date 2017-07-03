clear all
clc
close all
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/evaluation_using_FEM/
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/basic_RL_Hod/
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/Hod_operators/

settings_file;
w = rand(1,nF);
counter = 0;

%% Initialize basic 4bar starting point mechanism
while counter < epochs 
    tic
    TDlist = '';
    linklist = [];
    a_list = [];
    [I,H,M] = build_mech_gridworld(H0,TDlist,linklist,gridxy);
    s = get_state(I,H);
    [Q,a] = choose_action(s,w,counter,a_list);
    term = 0;

    while term == 0
        
        a_list = [a_list a];
        
        [Q,f_full] = get_Q(s,w);
        
        [s_new,r,feasible_design] = stepper(s,a);
            
        [Q_new,a_new] = choose_action(s_new,w,counter,a_list);
        Q
        Q_new
        difference = r+discount_rate*Q_new-Q;
        
        for i = 1:nF
            w(i) = w(i)+learning_rate*difference*f_full(i);
            if isnan(w(i))
                keyboard
            end
       
        end
        f_full
        w  
        [I,H] = state2IH(s_new);
        if size(I,1) >= (max_no_of_bars-2)
            term = 1;
        end
        s = s_new;
        a = a_new;
        
        r
    end
    f_full
    display('end of session')
    a_list
    nH = size(I,2)
    nM = size(I,1)
    
    display('COUNTER')
    counter = counter+1
    toc
end
