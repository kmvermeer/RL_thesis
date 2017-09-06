function output = eval_NN_dropout(weights,input,layer_settings,bias)
    
    layer_sizes = layer_settings.sizes;
    layer_styles = layer_settings.styles;
    dropout_rates = layer_settings.dropout_rates;
    
    
    
    nL = length(weights);
    
    %Perform input drop:
    random_nmbrs = rand(1,layer_sizes(1));
    input_mask = random_nmbrs > (1-dropout_rates(1));
    input_mask = double(input_mask);  
    input_drop = input .* input_mask;
    input = input_drop;
    
    
    for L = 1:nL
        
            if bias == false
                x = input*weights{L};
            else
                x = [input 1]*weights{L};
            end
            y = activation_NN(x,string(layer_styles(L)),false);
            
            %perform drop:
            random_nmbrs = rand(1,layer_sizes(L+1));
            mask = random_nmbrs > (1-dropout_rates(L+1));
            mask = double(mask);
            mask(end) = 1;      %Removing possible drop from bias
            y_drop = y.*mask;
%             y_drop = perform_dropout on y
            input = y_drop;
    end
    output = y;
end
    