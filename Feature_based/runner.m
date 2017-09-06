warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables

layer_settings.styles = {'Sigmoid','linear'};
layer_settings.dropout_rates = [0 0  0];
lr = 0.3;
decay_m = 0.95; 
decay_RMS = 0.99;
NN_trainer_style = 'Adams';
epochs = 500;
hidden_multiplier = 3;

%Pack settings into Cell structure
settings.layer_settings = layer_settings;
settings.lr = lr;
settings.decay_m = decay_m;
settings.decay_RMS = decay_RMS;
settings.NN_trainer_style = NN_trainer_style;
settings.epochs = epochs;
settings.hidden_multiplier = hidden_multiplier;

%Run main_NN
main_NN;

