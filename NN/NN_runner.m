%Following procdures from
%https://mattmazur.com/2015/03/17/a-step-by-step-backpropagation-example/ to test
%values. Code written by K.M. Vermeer - 24-07-2017
clear variables
close all
close all

%% Network settings
layer_settings.sizes = [2,30,1];
layer_settings.styles = {'leaky_ReLU','tanh'};
layer_settings.dropout_rates = [0 0 0];
layer_settings.regularization = [1e-4 1e-7];
lr = .1;
decay_m = 0.90; 
decay_RMS = 0.99;

for l = 1:length(layer_settings.sizes)-1
    %weight according to http://machinelearning.wustl.edu/mlpapers/paper_files/AISTATS2010_GlorotB10.pdf
    weight_factor = sqrt(6)/(sqrt(layer_settings.sizes(l)+layer_settings.sizes(l+1)+2));
    weights{l} = weight_factor*(2*rand(layer_settings.sizes(l)+1,layer_settings.sizes(l+1))-1);

end

epochs = 8100;

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
while k <= epochs && (moving_average_error > 0.001)
    weights = new_weights;
    input = train(k,:);
    current_truth = truth(k);
    [new_weights,grad,MS_grad,output,error,dEdW] = train_NN (weights, input, current_truth, ...
                                                            layer_settings, lr, decay_m,...
                                                            decay_RMS, grad, MS_grad, k,...
                                                            'Adams');
                                                       
    errors(k) = error;
    %Check whether terminal conditions are being met                                                    
    if k>50
        moving_average_error = mean(errors(k-50:k));
    end
    k = k+1;
end
errors(k:end) = [];


%% Testing results
test_set = randi(2,200,2)-1;
predictions = zeros(length(test_set),1);
true_values = predictions;
for tester = 1:length(test_set)
    output = eval_NN(weights,test_set(tester,:),layer_settings,true);
    true_values(tester) = xor(test_set(tester,1),test_set(tester,2));
    predictions(tester) = output;
end
wrongful_predictions = sum(abs(true_values - round(predictions)));
accuracy = (200-wrongful_predictions)/200*100;



%% Checking the gradients:
figure
plot(errors(1:k-1))
title('MSE vs iterations')
xlabel('MSE')
ylabel('Iterations')
grid on
fprintf('Finished after %i iterations',k)
disp(' ')
fprintf('Test showed %i%% accuracy',round(accuracy))

% [dEdW_grad] = gradient_check_NN (weights,layer_settings,[1 1],0);



