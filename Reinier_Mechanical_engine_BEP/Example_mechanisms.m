%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 18-10-2016                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all 
close all 
clc
warning off

%% Initialize empty DNA strand
DNA=initializeDNA;

%% Topology Definition
%Define the topology of the mechanism. The topology defines what parts are
%connected in what way. We assume the vertex set {G M1 M2 ... Mn}. If we
%want to connect the first mass M1 to the ground G we define a column
%vector [1;1]. Similarly, if we want to connect M1 and M2 we define a
%column vector [0;1;1]. 

DNA.incstr(1) = inc2str([1;1]);             %Connects G and M1
DNA.incstr(2) = inc2str([1;1]);             %Connects G and M1
DNA.incstr(3) = inc2str([1;0;1]);           %Connects G and M2
DNA.incstr(4) = inc2str([1;0;0;1]);         %Connects G and M3
DNA.incstr(5) = inc2str([0;0;0;1;1]);       %Connects M3 and M4

%% Edgetype Definition
%After we define what parts are connected, we need to define how they are
%connected. We have 4 options: 
%   1)rotational joint
%   2)spring
%   3)prismatic joint
%   4)prismatic motor
%It is important that prismatic joints can connect only to the ground. So a
%prismatic joint (and motor) cannot exist between two masses, e.g. M1 and  M2

DNA.edgelabel = [1 2 3 4 1]; 

%% Parameter Definition
%Mass data is contained in an Mx3 matrix. Each vertex is associated with a
%row. The first row (vertex) is the ground, it has no mass, so we set it to
%NaN. For the other 4 vertices (masses) we can set an initial x [m] and y
%[m] position and a mass [kg]. The x and y data is only used if only one
%connection is made to the mass. If two or more connections are made the
%dimensions of the mass are determined by the locations of these
%connections.
DNA.Mpar(1,:)  = NaN;                       
DNA.Mpar(2,:)  = [0 0 1];                   % [x-coordinate y-coordinate bodymass]
DNA.Mpar(3,:)  = [4 -1 1];                  % [x-coordinate y-coordinate bodymass]
DNA.Mpar(4,:)  = [-5 -1 1];                 % [x-coordinate y-coordinate bodymass]
DNA.Mpar(5,:)  = [-5 -8 1];                 % [x-coordinate y-coordinate bodymass]

%The data for the hinges is stored in an 5xN matrix. It includes an x and y 
%position, a stiffness coefficient, a damping coefficient and a preloading angle. 
DNA.Hpar(:,1)  = [0,0,0,0,0].';             % [x-coordinate y-coordiante K C preloading-angle]
DNA.Hpar(:,2)  = [-5,-2,0,0,0].';           % [x-coordinate y-coordiante K C preloading-angle]

%The data for the springs is stored in a 6xN matrix. It includes two x and
%y positions. The origo defines the first connection point, and the
%insertie defines the second connection point. The zero-length (L0) and the
%stiffness coefficient (K) are defined in the 5th and 6th entry
%respectively
DNA.Spar(:,1)  = [2,0,-1,-1,0,0].';         % [x-origo y-origo x-insertie y-insertie L0 K]

%The data for a prismatic joint is stored in a 3xN matrix. It includes an
%initial x and y position and an angle. 
DNA.Ppar(:,1)  = [5,0,0].';                 % [x-coordinate y-coordinate angle]

%The data for a prismatic motor is stored in an 3xN matrix. It includes an
%initial x and y position, an angle, an amplitude and a frequency. The
%motor function is equal to a*sin(w*t), where a is the amplitude and w is
%the frequency. 
DNA.Pmpar(:,1) = [-5,0,0,2,2].';            % [x-coordinate y-coordinate angle amplitude frequency]

%% Check for dof, connectivity and grounded
% Since in an EA we generate genotypes randomly we want to know if they are
% valid mechanisms. To that end, we check if there is mobility by checking
% the number of degress of freedom (DOF). We check if all parts are
% connected by hinges with isDNAconnected. And we check if the mechanism is
% fixed to at least one ground is isDNAgrounded.
dof         = getDOF(DNA);
connected   = isDNAconnected(DNA);
grounded    = isDNAgrounded(DNA);

%% Simulation + animation
T = 5;      %Simulation duration
h = 0.05;   %Step size

%There are two functions simulateDNA. The first one 'simulateDNA' is an
%ordinary matlab function (.m). The second one 'simulateDNA_mex' is called
%a matlab executable (mex) file. This file can be created by using the 
%'MATLAB coder' app. The mex function is way faster compared to ordinary
%matlabcode. Thus, for optimization, always use the mex file. 

[t,qss,flag]=simulateDNA(DNA,T,h);     %This is the non-mex version
% [t,qss,flag]=simulateDNA_mex(DNA,T,h);  %This is the mex version (way faster) 
animateDNA(DNA,t,qss);

%% Compute and plot all the trajectories
%This data can be used in the fitness function for example
[allT,nT] = getAllTrajectories(DNA,t,qss);
for k =1:nT
    plot(allT(:,k*2-1),allT(:,k*2))
end






