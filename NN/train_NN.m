%inputs: decay_m, decay_RMS, weights(struct),layers(struct),
%inputs, truth
%output: new_weights, output, error

function [new_weights,grad,MS_grad,output,error] = train_NN (weights, input, truth, layer_settings, lr, decay_m, decay_RMS, grad, MS_grad, epoch, update_style)
%% Training
    layer_sizes = layer_settings.sizes;
    layer_styles = layer_settings.styles;
    % Backprop to find dEdW
    dEdW = backprop(weights,layer_styles,input,truth);
    
    % Using Adams to update weights (https://arxiv.org/pdf/1412.6980v9.pdf)
    for layer = 1:(length(layer_sizes)-1)
        switch update_style
            case 'Adams'
                %Determine momentum-like variable
                grad{layer} = decay_m*grad{layer} + (1-decay_m) * dEdW{layer};
                grad_iter = grad{layer}./(1-decay_m^epoch);

                %Determine RMS-prop like squared error fun
                MS_grad{layer} = decay_RMS * MS_grad{layer} + (1-decay_RMS) * dEdW{layer}.^2;
                MS_grad_iter = MS_grad{layer}./(1-decay_RMS^epoch);

                %Perform update
                new_weights{layer} = weights{layer} -lr * grad_iter ./ (sqrt(MS_grad_iter) +1e-8);
            case 'SGD'
                grad{layer} = - lr * dEdW{layer};
                new_weights{layer} = weights{layer} + grad{layer};
            case 'SGD_momentum'
                grad{layer} = decay_m * grad{layer} - lr * dEdW{layer};
                new_weights{layer} = weights{layer} + grad{layer};
            case 'SGD_Nesterov_momentum'
                grad_previous = grad{layer};
                grad{layer} = decay_m * grad{layer}- lr *dEdW{layer};
                new_weights{layer} = weights{layer} -decay_m * grad_previous + (1+decay_m) * grad{layer};
            otherwise
                error_msg = strcat('Update style unknown: ',a);
                error(error_msg);
        end
                
    end
 
    output = eval_NN(new_weights,input,layer_settings,true);
    error = 1/2*(truth - output).^2;
end