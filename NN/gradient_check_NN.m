% function [dEdW_grad] = gradient_check_NN (weights,layer_settings,input,truth)
%     input = get_features(s,a);
%     truth= Q;
%     layer_settings.sizes = [length(weights{1})-1 length(weights{2})-1 1];
 input = [1 1];
    truth = 0;
    dEdW = backprop(weights,layer_settings,input,truth);
   
    e = 0.01;
    max_error_frac = 1e-3;
    
    
    for L = 1:length(weights)
        Wvec = reshape(weights{L},[numel(weights{L}),1]);
        FD_gradient = zeros(numel(weights{L}),1);
            
        for i = 1:numel(weights{L})
                       
            Wvec_gradUP = Wvec;
            Wvec_gradUP(i) = Wvec_gradUP(i)+e;
            W_gradUP = reshape(Wvec_gradUP,size(weights{L}));
            test_weights = weights;
            test_weights{L} = W_gradUP;
            outputUP = eval_NN(test_weights,input,layer_settings,true);          
            errorUP = 1/2*(truth - outputUP).^2;
            
            Wvec_gradDOWN = Wvec;
            Wvec_gradDOWN(i) = Wvec_gradDOWN(i)-e;
            W_gradDOWN = reshape(Wvec_gradDOWN,size(weights{L}));
            test_weights = weights;
            test_weights{L} = W_gradDOWN;
            outputDOWN = eval_NN(test_weights,input,layer_settings,true);          
            errorDOWN = 1/2*(truth - outputDOWN).^2;
            
            FD_gradient(i) = (errorUP-errorDOWN)/(2*e);
        end
        dEdW_grad{L} = reshape(FD_gradient,size(weights{L}));
    end
    
    %% Determining error fraction between numeric and backprop gradients
    
    error_fracs = zeros(1,length(weights));
    for L = 1:length(weights)
        error_fracs(L) = abs(mean(mean((dEdW_grad{L} - dEdW{L})./dEdW{L})));
    end
    if sum(error_fracs>max_error_frac)>0
        disp('Gradient check unsuccessful, please check errors')
    else
        disp('Gradient check successful')
    end
        
    
    
    
    %% Plotting
    figure
    plot(dEdW{1}(3,:),'square')
    hold on
    plot(dEdW_grad{1}(3,:),'*-')
    legend('backprop','FD')
    grid on

    

    


