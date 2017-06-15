



function [t,qss,flag] = simulateDNA_test
DNA.incstr    = [1 1 2 4];
DNA.edgelabel = [1 2 3 4];
DNA.Mpar  = zeros(0,3);
DNA.Hpar  = zeros(5,0);
DNA.Spar  = zeros(6,0);
DNA.Ppar  = zeros(3,0);
DNA.Pmpar = zeros(5,0);
DNA.fitness = 0;
DNA.bestTrajectory =zeros(0,2);

%Put in parameters for mechanism
DNA.Mpar(1,:)  = NaN;
DNA.Mpar(2,:)  = [0 0 1];
DNA.Mpar(3,:)  = [4 -1 1];
DNA.Mpar(4,:)  = [-5 -1 1];
DNA.Hpar(:,1)  = [0,0,0,0,0].';
DNA.Spar(:,1)  = [2,0,-1,-1,0,0].';
DNA.Ppar(:,1)  = [5,0,0].';
DNA.Pmpar(:,1) = [-5,0,0,1,1].';


T = 5;
h = 0.05;

[t,qss,flag] = simulateDNA(DNA,T,h);