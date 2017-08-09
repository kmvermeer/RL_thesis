%Following procdures from
%https://mattmazur.com/2015/03/17/a-step-by-step-backpropagation-example/ to test
%values. Code written by K.M. Vermeer - 24-07-2017

nI = 2;
nH = 2;
nO = 2;



% w1 = rand(nI,nH);
% w2 = rand(nH,nO);

w1 = [.15 .25 ; .20 .30 ; .35 .35];
w2 = [.40 .50 ;.45 .55 ; .60 .60];
weights.w1 = w1;
weights.w2 = w2;
errors = zeros(10000,0);
for k = 1:10000
    w1 = weights.w1;
    w2 = weights.w2;
    input = [.05 .10];
    truth = [.01 .99];
    layers = {'Sigmoid','Sigmoid'};
    
    %% Backprop

    yI = input;
    xH = [yI 1]*w1;
    yH = activation_NN(xH,'Sigmoid',false);
    xO = [yH 1]*w2;
    yO = activation_NN(xO,'Sigmoid',false);

    output = eval_NN(weights,input,layers,true);

    Etot = sum(1/2*(truth-yO).^2);
    errors(k) = Etot;
    %Backprop:
    
    
    
    %output layer
    delta_O = -(truth-yO) .* activation_NN(yO,'Sigmoid',true);
    dEdw2 = yH' *delta_O;
    dEdb2 = delta_O;
    w2_new = w2-0.5*[dEdw2;dEdb2];

    %hidden layer
    delta_H = (delta_O*w2(1:nH,:))  .*activation_NN(yH,'Sigmoid',true);
    dEdw1 = yI' *delta_H;
    dEdb1 = delta_H;
    w1_new = w1 - 0.5 * [dEdw1 ; dEdb1];
    weights.w1 = w1_new;
    weights.w2 = w2_new;
    output_new = eval_NN(weights,input,layers,true);
end

