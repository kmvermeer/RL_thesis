warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables

layer_settings.styles = {'Sigmoid','linear'};
layer_settings.dropout_rates = [0 0  0];
regularization = [1e-4 1e-3]; %L1 and L2 regularization
% regularization = [0 0];
lr = 0.1;
decay_m = 0.90; 
decay_RMS = 0.99;
NN_trainer_style = 'Adams';
epochs = 5000;
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

disp('Setting up parallel pool')
try 
    gcp;
catch 
    parallel_pool = parpool('local');
end
%Run main_NN
disp('Running main file')
main_NN;
delete(parallel_pool)
