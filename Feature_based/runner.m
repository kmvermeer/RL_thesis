warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/

% types = {'SGD','SGD_momentum','SGD_Nesterov_momentum','Adams'};
types = {'Adams'};
activation_styles = [{'Sigmoid','linear'},{'leak_ReLU','linear'}];
lrs = [.1,.3];
hidden_multipliers = [0.1,1,4];
max_epochs = 6000;
max_error =1e-3;

for i = 1:(length(activation_styles)/2)
    for j = 1:length(lrs)
        for k = 1:length(hidden_multipliers)
            tic
            start_time = datestr(now);
            lr_str = num2str(lrs(j));
            hidden_size_str = num2str(hidden_multipliers(k));
            disp(strcat('Started',' learning with LR = ',lr_str, 'and hidden layer multiplier',hidden_size_str,' on ',start_time))
            [weights,error_list,Qlist_all,alist_all,total_rewards] = main_NN_function(lrs(j),types{1},activation_styles(2*i-1:2*i),hidden_multipliers(k),max_error,max_epochs);
            save_string = strcat('LR ',lr_str,'Styles ',activation_styles(2*i-1),'hidden_multip_',hidden_size_str,'.mat');
            save(save_string{1},'weights','error_list','Qlist_all','alist_all','total_rewards')
            toc
            disp(strcat('Finished ',activation_styles{i},'with LR = ',lr_str))
        end

    end
end
        
