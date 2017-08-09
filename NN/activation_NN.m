function [output] = activation_NN(input,style,varargin)


    switch style
        case 'Sigmoid'
            if nargin ==3 & varargin{1} == true
                output = input.*(1-input)+0.1;  %Add 0.1: Fahlman's trick
            else                
                output = 1./(1 + exp(-input));
            end
        case 'ReLU'
            if nargin == 3 & varargin{1} == true
                output = input>0;
                output = double(output);
            else
                output = poslin(input);
            end
        case 'linear'
        if nargin == 3 & varargin{1} == true
            output = 1;
        else
            output = input;
        end
        otherwise
            error('Activation function unknown')
    end
    

end