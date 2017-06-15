%Code by K.M. Vermeer
tic()
%Code created on May 1st 2017
clear all
close all
%Initialising:
h1 = [0,0];
h2 = [4,0];
h3 = [0,1];
h4 = [3,2];

H0 = [h1;h2;h3;h4];
TDlist = 'DDTDTDDT';
linklist = [3,3,1,3,4,5,8,6,4,4];

[I,H,M] = build_mech(H0,TDlist,linklist);
nM = size(M,1);
nH = size(H,1);
% plot_mech(I,H,M);

%% Kinematic Analysis

%Get state vector q and constraints vector F
[F,q_symb,q,q0] = create_F_q(I,H,M);
%determine jacobians
dFdQ = jacobian(F,q);
matlabFunction(F,'File','getF','Vars',{q_symb});
matlabFunction(dFdQ,'File','getdFdQ','Vars',{q_symb})

q = q0;

%% NR
evals = 100;
X0 = H(1,1);
Y0 = H(1,2);
Xend = H(2,1);
Yend = H(2,2);
plot_mech(I,H,M)

% [x,y]=NR_analysis(q,q0,evals,nM,nH,X0,Y0,Xend,Yend);


%% Score motion for straightness
% trajectory_analysis(x,y);
plot_mech(I,H,M)


%% plot
% animate_motion(I,x,y,nM,evals)


toc()

