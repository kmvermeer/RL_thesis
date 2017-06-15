clc
clear all
close all

addpath /Users/kazv/Documents/TU/Thesis/MATLAB/evaluation_using_FEM/
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/Hod_operators/

%Initialising:
h1 = [0,0];
h2 = [2,0];
h3 = [1,3];
h4 = [3,2];

H0 = [h1;h2;h3;h4];
[I,H,M] = build_mech(H0,[],[]);
[i,j] = find(I);


a = 'T4';
s = get_state(I,H)

% [s_new,r,I,H,M] = stepper(I,H,M,a);


