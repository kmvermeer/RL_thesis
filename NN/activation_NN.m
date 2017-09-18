function [output] = activation_NN(input,style,varargin)


    switch style
        case 'Sigmoid'
            if nargin == 3 & varargin{1} == true
                output = input.*(1-input) + .1;     %Add 0.1: Fahlman's trick (intereres with gradient checks!)
            else                
                output = 1./(1 + exp(-input));
            end
        case 'ReLU'
            if nargin == 3 & varargin{1} == true
                output = 1 * (input>0);      
            else
                output = input .* (input>0);
            end
        case 'leaky_ReLU'
            if nargin == 3 & varargin{1} == true
                output = input;
                output(input>=0) = 1;
                output(input<0) = .01;       
            else
                output = input;
                output(output<0) = output(output<0)*.01;
            end
        case 'linear'
            if nargin == 3 & varargin{1} == true
                output = ones(size(input));
            else
                output = input;
            end
        case 'tanh'
            if nargin == 3 & varargin{1} == true
                output = 1- input.^2;
            else
                output = 2./(1+exp(-2*input))-1;
            end
            
        otherwise
            error('Activation function unknown')
    end
    

end