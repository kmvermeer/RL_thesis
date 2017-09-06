warning off;
addpath ../evaluation_using_FEM/
addpath ../basic_RL_Hod/
addpath ../NN/
addpath ../graphs/
clear variables

layer_settings.styles = {'Sigmoid','linear'};
layer_settings.dropout_rates = [0.2 0.5 0];
lr = 0.3;
decay_m = 0.95; 
decay_RMS = 0.99;
NN_trainer_style = 'Adams_maxnorm';
epochs = 20;
hidden_multiplier = 3;

%Pack settings into Cell structure
settings.layer_settings = layer_settings;
settings.lr = lr;
settings.decay_m = decay_m;
settings.decay_RMS = decay_RMS;
settings.NN_trainer_style = NN_trainer_style;
settings.epochs = epochs;
settings.hidden_multiplier = hidden_multiplier;

DR1s = [0 0.2];
DR2s = [0 0.35];
trainer_styles = {'Adams','Adams_maxnorm'};
LRs = [1e-3 ,1e-2 ,1e-1];


for DR1 = 1:length(DR1s)
    for DR2 = 1:length(DR2s)
        for TS = 1:length(trainer_styles)
            for LR = 1:length(LRs);
                
            start_time = datestr(now);
            lr_str = num2str(LRs(LR));
            DR1_str = num2str(DR1s(DR1));
            DR2_str = num2str(DR2s(DR2));
            disp('Started new optimization procedure')
            settings.layer_settings.dropout_rates = [DR1s(DR1) DR2s(DR2) 0];
            settings.trainer_style = trainer_styles(TS);
            
            main_NN;
            
            save_string = strcat('LR_',lr_str,trainer_styles(TS),'_DR1_',DR1_str,'_DR2_',DR2_str,'.mat');
            save(save_string{1},'weights','error_list','Qlist_all','alist_all','run_time')
            disp('Finished optimization procedure')
            
            end
        end
    end
end
        
