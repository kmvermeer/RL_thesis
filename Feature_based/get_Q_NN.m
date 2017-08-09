function [Q,F] = get_Q_NN(s,a,weights,layer_settings)
    settings_file;
   
    [F] = get_features(s,a);
        
    Q = eval_NN(weights,F,layer_settings,true);
end