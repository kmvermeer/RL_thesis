warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables



try
    %for i in {1..4}; do for ii in {1..28}; do qsub -v alog_ix=$i,variable_ix=$ii jobv_runner.pbs; done; done
    %for i in {1..28}; do qsub -v variable_ix=$i job_runner.pbs; done
    variable_ix = str2num(getenv('variable_ix'));
    fprintf('Running variable ix %i\n',variable_ix);
    algo_ix = str2num(getenv('algo_ix'));
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
epochs = 5;
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

vars.DR1s = [0.1 0.2];                                             %layer settings
vars.DR2s = [0.30 0.5];                                            %layer settings
vars.layer_types = {'tanh','ReLU','leaky_ReLU'};                     %layer settings
vars.trainer_styles = {'SGD','SGD_Nesterov_momentum','Adams'};
vars.LRs = [1e-3 ,1e-2 ,1];
vars.neg_rewards = [-25 -1 0];
vars.expl_factors = [30,300];
vars.hidden_mltps = [.25 .5 4 16];
vars.L1 = [1e-4 1e-3 1e-2];
vars.L2 = [1e-4 1e-3 1e-2];

var_lengths = cellfun(@length, struct2cell(vars(:)));
vars_ix = min(find(cumsum(var_lengths)>=variable_ix,1));
value_ix = variable_ix - sum(var_lengths(1:vars_ix-1));

names = fieldnames(vars);

%Setting up the right variable name index and value index
       

V = vars_ix;
values = getfield(vars,names{V});
ix = value_ix;

switch names{V}
    case 'DR1s'
        settings.layer_settings.dropout_rates(1) = values(ix);
        value_string = num2str(values(ix));
        if values(ix)>0
            settings.lr = 1;
        end

    case 'DR2s'
        settings.layer_settings.dropout_rates(2) = values(ix);
        value_string = num2str(values(ix));
        if values(ix)>0
            settings.lr = 1;
        end

    case 'layer_types'
        settings.layer_settings.styles(1) = values(ix);
        value_string = values{ix};         

    case 'trainer_styles'
        settings.NN_trainer_style = values{ix};
        value_string = values{ix};
        if not(strcmp(settings.NN_trainer_style,'Adams'))
            settings.lr = 1e-3;             %Decreasing stepsize for SGD type solutions
        end

    case 'LRs'
        settings.lr = values(ix);
        value_string = num2str(values(ix));

    case 'neg_rewards'
        settings.negative_reward = values(ix);
        value_string = num2str(values(ix));
    case 'expl_factors'
        settings.expl_factor = values(ix);
        value_string = num2str(values(ix));
    case 'hidden_mltps'
        settings.hidden_multiplier = values(ix);
        value_string = num2str(values(ix));
    case 'L1'
        settings.regularization(1) = values(ix);
        value_string = num2str(values(ix));
    case 'L2'
        settings.regularization(2) = values(ix);
        value_string = num2str(values(ix));
end        

        

switch algo_ix
    case 1
        main_NN
        algo_string = 'TD';
    case 2
        main_NN_MC
        algo_string = 'MC';
    case 3
        main_NN_end_reward
        algo_string = 'TD_end';
    case 4
        main_NN_MC_end_reward
        algo_string = 'MC_end';
end
save_string = strcat('../results/',algo_string,'_',names{V},'_',value_string,'.mat');
disp(save_string)   

save(save_string)  
fprintf('Finished run no %i over %s',[ix names{V}])
    

       
% delete(gcp('nocreate'))
exit

