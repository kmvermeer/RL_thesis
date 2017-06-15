clear all
close all
clc
tic

w = warning('on','all');
warning('off','all')

%Initialising:
h1 = [0,0];
h2 = [2,0];
h3 = [1,3];
h4 = [3,2];

H0 = [h1;h2;h3;h4];
[I,H,M] = build_mech(H0,[],[]);
[i,j] = find(I);
s = zeros(20,1)-1;
s(1:numel(i)) = i;
a = 'T4';

[s_new,r,I,H,M] = stepper(I,H,M,a);



toc