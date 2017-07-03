clear all
clc
close all
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/evaluation_using_FEM/
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/basic_RL_Hod/
addpath /Users/kazv/Documents/TU/Thesis/MATLAB/Hod_operators/
settings_file;

%% Initialize basic 4bar starting point mechanism
TDlist = '';
linklist = [];
[I,H,M] = build_mech_gridworld(H0,TDlist,linklist,gridxy);
s = get_state(I,H,gridxy,max_no_of_hinges);

%% Perform a step
%Action_list is as follows: D1 T1 D2 T2 D3 T3... ...D9 T9 D10 T10
a =3;
[s_new,r] = stepper(s,a);

[I,H] = state2IH(s_new);
plot_mech(I,H);



zero_inc_str = zeros(1,max_no_of_hinges);
zero_inc_str(end-1:end) = 1;
max_inc = I2str(zero_inc_str);

% rI = max_inc;
% nH_locations = gridlength^2;
% nA = max_no_of_hinges-4;
% 
% 
% N = zeros(rI,rI,rI,rI,rI,rI,rI,rI,rI,rI,nH,nH,nH,nH,nH,nH,nH,nA);
% Q = N
% V = zeros(rI,rI,rI,rI,rI,rI,rI,rI,rI,rI,nH,nH,nH,nH,nH,nH,nH);

