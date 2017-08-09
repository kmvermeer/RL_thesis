function output = eval_NN(weights,input,layer_settings,bias)
    layer_styles = layer_settings.styles;
    nL = length(weights);
    
    if bias == false
        %forward propagation:
        for L = 1:nL
            x = input*weights{L};
            y = activation_NN(x,string(layer_styles(L)),false);
            input = y;
        end
    else
        %forward propagation:
        for L = 1:nL
            x = [input 1]*weights{L};
            y = activation_NN(x,string(layer_styles(L)),false);
            input = y;
        end
    end
    output = y;
end
    
    
    
    