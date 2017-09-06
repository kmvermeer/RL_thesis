function [Q,F] = get_Q_NN(s,a,weights,layer_settings)
    settings_file;
   
    [F] = get_features(s,a);
        
    try
        Q = eval_NN(weights,F,layer_settings,true);
    catch
        keyboard
    end
end