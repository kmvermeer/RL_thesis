warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables
reset(RandStream.getGlobalStream, sum(100*clock))


try
    %for i in {1..4}; do for ii in {1..3}; do qsub -v action_ix=$i,expl_ix=$ii job_runner.pbs; done; done
    %for i in {1..28}; do qsub -v variable_ix=$i job_runner.pbs; done
    %for i in {1..11}; do qsub -v penalty_ix=$i job_runner.pbs; done
    penalty_ix = str2num(getenv('penalty_ix'));
    fprintf('Running penalty_ix %i\n',penalty_ix);
catch
    disp('Running localy, no cluster')
end

disp('Setting up grid search')


layer_settings.styles = {'Sigmoid','linear'};
layer_settings.dropout_rates = [0 0  0];
% regularization = [1e-4 1e-3]; %L1 and L2 regularization
regularization = [.001 .001];
lr = 1e-3;
decay_m = 0.90; 
decay_RMS = 0.99;
NN_trainer_style = 'Adams';
epochs = 10e3;
hidden_multiplier = .75;
negative_reward = -25;
expl_factor = 30;
hinge_limit = 10;
large_structure_penalty = 0.75;

%Pack settings into Cell structure
settings_struct.layer_settings = layer_settings;
settings_struct.lr = lr;
settings_struct.decay_m = decay_m;
settings_struct.decay_RMS = decay_RMS;
settings_struct.NN_trainer_style = NN_trainer_style;
settings_struct.epochs = epochs;
settings_struct.hidden_multiplier = hidden_multiplier;
settings_struct.regularization = regularization;
settings_struct.negative_reward = negative_reward;
settings_struct.expl_factor = expl_factor;
settings_struct.hinge_limit = hinge_limit;
settings_struct.large_structure_penalty = large_structure_penalty;
base_settings = settings_struct;
penalties = [1 0.9 .8 .7 .6 .5 .4 .3 .2 .1 0];                                            %layer settings

settings_struct.large_structure_penalty = penalties(penalty_ix);

main_NN;
%Saving
penalty_str = num2str(penalties(penalty_ix));
save_string = strcat('../results_penalties/',penalty_str,'.mat');
disp(save_string)   
save(save_string)  
       
exit

