
function [layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,hidden_multiplier] = get_NN_settings(settings)
    layer_settings = settings.layer_settings;
    lr = settings.lr;
    decay_m = settings.decay_m;
    decay_RMS = settings.decay_RMS;
    NN_trainer_style = settings.NN_trainer_style;
    epochs = settings.epochs;
    hidden_multiplier = settings.hidden_multiplier;
end
