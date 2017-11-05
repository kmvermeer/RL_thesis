
function [layer_settings,lr,decay_m,decay_RMS,...
          NN_trainer_style,epochs,hidden_multiplier,...
          negative_reward,expl_factor,max_no_of_hinges,...
          max_no_of_bars,nA,large_structure_penalty] = get_NN_settings(settings_struct)
      
    layer_settings = settings_struct.layer_settings;
    lr = settings_struct.lr;
    decay_m = settings_struct.decay_m;
    decay_RMS = settings_struct.decay_RMS;
    NN_trainer_style = settings_struct.NN_trainer_style;
    epochs = settings_struct.epochs;
    hidden_multiplier = settings_struct.hidden_multiplier;
    negative_reward = settings_struct.negative_reward;
    expl_factor = settings_struct.expl_factor;
    max_no_of_hinges = settings_struct.hinge_limit;
    
    max_no_of_bars = (max_no_of_hinges - 4)*2+4;
    nA = 2*max_no_of_bars;
    large_structure_penalty = settings_struct.large_structure_penalty;

end


