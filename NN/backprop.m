function dEdW = backprop(weights,style,input,truth)
 
    
    nL = length(weights);
    
    if nL == 2
        style1 = string(style{1});
        style2 = string(style{2});
        w1 = weights{1};
        w2 = weights{2};
        nH = size(w1,2);
        yI = input;
        xH = [yI 1]*w1;
        yH = activation_NN(xH,style1,false);
        xO = [yH 1]*w2;
        yO = activation_NN(xO,style2,false);
          
        %output layer
        delta_O = -(truth-yO) .* activation_NN(yO,style2,true);
        dEdb2 = delta_O;
        dEdw2 = [yH' *delta_O; dEdb2];
        
        %hidden layer
        delta_H = (delta_O*w2(1:nH,:))'  .*activation_NN(yH,style1,true);
        dEdb1 = delta_H;
        dEdw1 = [yI' *delta_H; dEdb1];
        
        
        dEdW{1} = dEdw1;
        dEdW{2} = dEdw2;
 
    elseif nL == 3
        w1 = weights{1};
        w2 = weights{2};
        w3 = weights{3};
        nH1 = size(w1,2);
        nH2 = size(w2,2);
        style1 = string(style{1});
        style2 = string(style{1});
        style3 = string(style{1});
        yI = input;
        xH1 = [yI 1]*w1;
        yH1 = activation_NN(xH1,style1,false);
        xH2 = [yH1 1] * w2;
        yH2 = activation_NN(xH2,style2,false);
        xO = [yH2 1]*w3;
        yO = activation_NN(xO,style3,false);
          
        %output layer
        delta_O = -(truth-yO) .* activation_NN(yO,style3,true);
        dEdb3 = delta_O;
        dEdw3 = [yH2' *delta_O; dEdb3];

        %hidden layer 2
        delta_H2 = (delta_O*w3(1:nH2,:))'  .*activation_NN(yH2,style2,true);
        dEdb2 = delta_H2;
        dEdw2 = [yH1' * delta_H2; dEdb2];
        
        %hidden layer 1
        delta_H1 = delta_H2*(w2(1:nH1,:)')  .*activation_NN(yH1,style1,true);
        dEdb1 = delta_H1;
        dEdw1 = [yI' *delta_H1; dEdb1];
        
        dEdW{1} = dEdw1;
        dEdW{2} = dEdw2;
        dEdW{3} = dEdw3;
    else
        error('wrong number of layers: can only cope with 2 or 3')
        

    end 
    %Add momentum
    mr = 0.5;
end





