clear all
clc

lambdas = 0:0.1:1;
errors = [];

for x=1:11
    lambda = lambdas(x);
    [Q,N,V,score,MSE_vec] = TD_fun(lambda);
    errors = [errors;MSE_vec(end)];
end