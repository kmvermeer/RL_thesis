function output = eval_NN(weights,input,layer_settings,bias)
    layer_styles = layer_settings.styles;
    nL = length(weights);
    
    
    
    for L = 1:nL
            weights{L}(1:end-1,:) = weights{L}(1:end-1,:);
            if bias == false
                x = input*weights{L};
            else
                x = [input 1]*weights{L};
            end
            y = activation_NN(x,string(layer_styles(L)),false);
            input = y;
    end
    output = y;
end
    
    
    
    