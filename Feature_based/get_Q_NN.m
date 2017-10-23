function [Q,F] = get_Q_NN(s,a,weights,layer_settings,max_no_of_hinges,max_no_of_bars)
    
    [F] = get_features(s,a,max_no_of_hinges,max_no_of_bars);
        
    try
        Q = eval_NN(weights,F,layer_settings,true);
    catch
        keyboard
    end
end