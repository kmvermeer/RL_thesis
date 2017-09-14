warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables

try
    %for i in {1..4}; do qsub -v variable_ix=$i job_runner.pbs; done
    variable_ix = str2num(getenv('variable_ix'));
    save('variable_name','variable_ix');
    fprintf('Running variable ix %i',variable_ix);
catch
    disp('Running localy, no cluster')
end

disp('Setting up grid search')

layer_settings.styles = {'Sigmoid','linear'};
layer_settings.dropout_rates = [0 0  0];
regularization = [0 0]; %L1 and L2 regularization
lr = 0.1;
decay_m = 0.90; 
decay_RMS = 0.99;
NN_trainer_style = 'Adams';
epochs = 2;
hidden_multiplier = .75;
negative_reward = -5;

%Pack settings into Cell structure
settings.layer_settings = layer_settings;
settings.lr = lr;
settings.decay_m = decay_m;
settings.decay_RMS = decay_RMS;
settings.NN_trainer_style = NN_trainer_style;
settings.epochs = epochs;
settings.hidden_multiplier = hidden_multiplier;
settings.regularization = regularization;
settings.negative_reward = negative_reward;
settings.expl_factor = 100;

base_settings = settings;

vars.DR1s = [0 0.2];                                             %layer settings
vars.DR2s = [0 0.30];                                            %layer settings
vars.layer_types = {'leaky_ReLU','Sigmoid'};                     %layer settings
vars.trainer_styles = {'SGD','SGD_Nesterov_momentum','Adams'};
vars.LRs = [1e-3 ,1e-2 ,1e-1,1];
vars.neg_rewards = [-25 -5 -1 0];
vars.expl_factors = [30,100,300];
vars.hidden_mltps = [.5 1 2 4];
names = fieldnames(vars);

try
    names = names(variable_ix);             %This is for cluster running
catch
    names = names;
end
        

for V = 1:length(names)
    values = getfield(vars,names{V});
    for ix = 1:length(values)
        settings = base_settings;
        switch names{V}
            case 'DR1s'
                settings.layer_settings.dropout_rates(2) = values(ix);
                value_string = num2str(values(ix));

            case 'DR2s'
                settings.layer_settings.dropout_rates(3) = values(ix);
                value_string = num2str(values(ix));

            case 'layer_types'
                settings.layer_settings.styles(1) = values(ix);
                value_string = values{ix};         
                
            case 'trainer_styles'
                settings.NN_trainer_style = values{ix};
                value_string = values{ix};
                
            case 'LRs'
                settings.LRs = values(ix);
                value_string = num2str(values(ix));
                
            case 'neg_rewards'
                settings.negative_reward = values(ix);
                value_string = num2str(values(ix));
            case 'expl_factors'
                settings.N0 = values(ix);
                value_string = num2str(values(ix));
            case 'hidden_mltps'
                settings.hidden_multiplier = values(ix);
                value_string = num2str(values(ix));
        end        
   
        save_string = strcat('../results/',names{V},'_',value_string,'.mat');
        disp(save_string)           
        main_NN
        save(save_string,'weights','error_list','Qlist_all','alist_all',...
            'run_time','total_reward_list','settings','total_reward')
        fprintf('Finished run no %i over %s',[ix names{V}])
    end
end
       
% delete(gcp('nocreate'))
exit

