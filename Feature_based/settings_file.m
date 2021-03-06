%% Constants and Settings:

err = 1e-4; %FEA issue
lr_FEA = 1; %gradient decent starting point
evals = 300;
max_iter = 100;
total_rotation = 2*pi;


%% Initialize structure:

%Initialising:
h1 = [3,5.1];
h2 = [7.2,5.4];
h3 = [3.8,6.2];
h4 = [6.9,7.1];

H0 = [h1;h2;h3;h4];


%% RL settings
discount_rate = 1;
learning_rate = 0.001;  %0.001 works well with the linear approximation approach
% epochs = 5000;      %Good results on 5k
