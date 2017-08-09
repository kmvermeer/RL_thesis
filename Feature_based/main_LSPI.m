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
drawnow
wlist = w;    
rlist = [0];
Qlist = [0];
deltalist = [0];
alist_all = [];
errs = []
ws = [];
epochs = 1;

%% running
while epochs<25
    [I,H] = initIH;
    s = get_state(I,H);

    sample_count = 0;
    sample.state = s;
    sample.action = 0;
    sample.reward = 0;
    sample.new_state = s;


%% Gaining Sample struct D
    while sample_count < 10
        [I,H] = initIH;
        s = get_state(I,H);
        a_list = [];
        term = 0;
        while term ~= 1
            [Q_new,a] = choose_action(s,w,1e5,[a_list]);
            [s_new,r] = stepper(s,a);
            a_list = [a_list a];
            new_sample.state = s;
            new_sample.action = a;
            new_sample.reward = r;
            new_sample.new_state = s_new;
            sample_count = sample_count+1;
            sample(end+1) = new_sample;


            [I,H] = state2IH(s_new);
            if size(I,1) >= (max_no_of_bars-2)
                term = 1;
            else
                s = s_new;
            end
        end
    end
    disp('Performed sampling')

    %% Performing LSTDQ
    iter = 0;
    err = 5;
    tic
    while err>1 && iter<10
        A = 0.001 * eye(nF,nF);
%         A = zeros(nF,nF);
        
        B = (1/0.0001) * eye(nF,nF);
        b = zeros(nF,1);
        samples = sample(2:end);
        nD = size(samples,2);
        for i = 1:nD
            s = samples(i).state;
            a = samples(i).action;
            r = samples(i).reward;
            s_new = samples(i).new_state;
            [~,a_new] = choose_action(s,w,1e5,[]);

            Fsa = get_features(s,a)';
            Fnext = get_features(s_new,a_new)';
            
            
%             %% Trying something out from github
%             nf = Fsa-discount_rate*Fnext;
%             uv = Fsa*nf';
%             N = B*uv*B;
%             d = 1+nf'*B*Fsa;
%             B = B - N/d;
%             b = b+ Fsa*r;
%             
%             %% end

%             top = B*Fsa*(Fsa-discount_rate*Fnext)'*B;
%             bottom = 1+ (Fsa-discount_rate*Fnext)'*B*Fsa;
%  
%             B = B-top/bottom;
%             b = b+Fsa*r;

            A =A + Fsa*(Fsa - discount_rate*Fnext)';
            b = b + Fsa *r;       
            
        end
%         w_new = B*b;
        rankA = rank(A);
        if rankA == nF
            w_new = A\b;
        else
            disp('Low rank A matrix')
            w_new = pinv(A)*b;
        end
        
        w_new = w_new';     %This makes it LSPI
        err = norm(w-w_new)
        error_vec = w-w_new;
        ws = [ws;w_new];
        errs = [errs;error_vec];
        iter = iter+1
        hold on
        w = w_new;
    end
    toc
    disp('Performed LSPI')
    barplot.YData = w;
    barplot_text.String = strcat('Epochs: ',int2str(epochs));
    drawnow
    clear sample
    epochs = epochs +1
end


csvwrite('weights.dat',w)
exit

