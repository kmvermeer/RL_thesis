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
Qlist = [0];
deltalist = [0];
alist_all = [];

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

    while term == 0
        
        a_list = [a_list a];
        
        [Q,F] = get_Q(s,a,w);
        
        [s_new,r,feasible_design] = stepper(s,a);
        [Q_new,a_new] = choose_action(s_new,w,counter,a_list);
        delta = r+discount_rate*Q_new-Q;
        
        for i = 1:nF
            update = learning_rate*delta*F(i);
%             if update>6
%                 update = 6;
%             elseif update<-6
%                 update = -6;
%             end
            
            w(i) = w(i)+update;
            if isnan(w(i))
                keyboard
            end
       
        end
        wlist= [wlist;w];
        [I,H] = state2IH(s_new);
        if size(I,1) >= (max_no_of_bars-2)
            term = 1;
        end
        s = s_new;
        a = a_new;
        deltalist=[deltalist;delta];
        Qlist = [Qlist;Q];
        rlist = [rlist;r];
        
    end
    alist_all = [alist_all;a_list(:)];
    counter = counter+1;
    barplot.YData = w;
    barplot_text.String = strcat('Epochs: ',int2str(counter));
    drawnow
    if mod(counter,10)==0
        disp('COUNTER')
        disp(counter)
        disp(r)
    end
end

disp('Finished all epochs')
load train
sound(y,2*Fs)
toc(tstart)


