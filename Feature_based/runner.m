warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/

types = {'SGD','SGD_momentum','SGD_Nesterov_momentum','Adams'};
lrs = [1e-3,1e-2,1e-1,3e-1,5e-1,7.5e-1];
max_epochs = 5e3;
max_error =1e-3;

for i = 1:length(types)
    for j = 1:length(lrs)
        start_time = datestr(now);
        disp(strcat('Started',types{i},' learning with LR = ',lr_str,' on ',start_time))
        [weights,error_list,Qlist_all,alist_all] = main_NN_function(lrs(j),types{i},max_error,max_epochs);
        test1 = 3;
        test2 = j;
        lr_str = num2str(lrs(j));
        save_string = strcat('LR ',lr_str,'type ',types{i},'.mat');
        save(save_string,'weights','error_list','Qlist_all','alist_all')
    end
    disp(strcat('Finished ',types{i},' learning with LR = ',lr_str))
end
        
