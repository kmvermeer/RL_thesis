warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables

layer_settings.styles = {'Sigmoid','linear'};
layer_settings.dropout_rates = [0 0  0];
% regularization = [1e-4 1e-3]; %L1 and L2 regularization
regularization = [.001 .001];
lr = 1e-3;
decay_m = 0.90; 
decay_RMS = 0.99;
NN_trainer_style = 'Adams';
epochs = 5e3;
hidden_multiplier = .75;
negative_reward = -25;
expl_factor = 30;
hinge_limit = 10;


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


%Run main_NN
disp('Running main file')
main_NN
folder_name = strcat('results_',datestr(now,'yyyymmdd_ss'));
cd ..
mkdir(folder_name);
cd(folder_name)
save_string = strcat(folder_name,'.mat');
save(save_string);


%qsub -v job_runner.pbs;



