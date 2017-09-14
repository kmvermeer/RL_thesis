% [I,H] = initIH;
% s = get_state(I,H);
% tic
% 
% for k = 1:50
%     parfor a = 1:10
%         Q_new = get_Q_NN(s,a,weights,layer_settings);  
%     end
% end
% partime = toc;
% 
% average_runtime_tpar = partime/50
% 
% tic
% for k = 1:50
%     for a = 1:10
%         Q_new = get_Q_NN(s,a,weights,layer_settings);  
%     end
% end
% 
% normal_time = toc;
% average_runtime_normal = normal_time/50
% 

disp('This is working')
exit
