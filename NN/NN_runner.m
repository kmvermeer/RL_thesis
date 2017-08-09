%Following procdures from
%https://mattmazur.com/2015/03/17/a-step-by-step-backpropagation-example/ to test
%values. Code written by K.M. Vermeer - 24-07-2017
clear variables
close all
close all

%% Network settings
layer_settings.sizes = [2,4,1];
layer_settings.styles = {'Sigmoid','Sigmoid','linear'};
lr = 0.75;
decay_m = 0.9; 
decay_RMS = 0.99;

for l = 1:length(layer_settings.sizes)-1
    weights{l} = 2*rand(layer_settings.sizes(l)+1,layer_settings.sizes(l+1))-1;
end

epochs = 10000;

%% Initialization & Dataset creation
errors = ones(1,epochs)*999;
moving_average_error = 1;
    
train = randi(2,epochs,2)-1;
truth = zeros(epochs,1);
for i = 1:length(truth)
    truth_single = xor(train(i,1),train(i,2));
    truth(i) = truth_single;
end

new_weights = weights;

grad = cellfun(@(x) x*0,new_weights,'uni',false);
MS_grad = cellfun(@(x) x*0,new_weights,'uni',false);

    

%% Training
k = 1;
while k <= epochs && (moving_average_error > 1e-3)
    weights = new_weights;
    input = train(k,:);
    current_truth = truth(k);
    [new_weights,grad,MS_grad,output,error] = train_NN (weights, input, current_truth, ...
                                                            layer_settings, lr, decay_m,...
                                                            decay_RMS, grad, MS_grad, k,...
                                                            'SGD');
                                                       
    errors(k) = error;
    %Check whether terminal conditions are being met                                                    
    if k>10
        moving_average_error = mean(errors(k-10:k));
    end
    k = k+1;
end

%% Testing results
test_set = randi(2,200,2)-1;
predictions = zeros(length(test_set),1);
true_values = predictions;
for tester = 1:length(test_set)
    output = eval_NN(weights,test_set(tester,:),layer_settings,true);
    true_values(tester) = xor(test_set(tester,1),test_set(tester,2));
    predictions(tester) = output;
end

plot(errors(1:k-1))
title('MSE vs iterations')
xlabel('MSE')
ylabel('Iterations')
grid on
afprintf('Finished after %i iterations',k)

