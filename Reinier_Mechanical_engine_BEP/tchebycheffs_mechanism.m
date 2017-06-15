
clear all; close all; clc
   

DNA = initializeDNA;

inc = [ 1   0   0   1     0   0   0   1;
        1   1   0   0     0   0   0   0;
        0   1   1   0     1   0   0   0;
        0   0   1   1     0   0   1   0;
        0   0   0   0     1   1   0   1;
        0   0   0   0     0   1   1   0]; 
    
DNA.incstr      = inc2str(inc);
DNA.edgelabel   = [1 1 1 1  1 1 1 2];

DNA.Mpar        = [[NaN,NaN,NaN];rand(length(inc(:,1))-1,3)];

DNA.Hpar = [[0;0],[4.5;6],[1.5;6],[6;0],[3;6],[6;6],[3.75;3] ];
DNA.Hpar(3:5,:)=0;
DNA.Spar = [9;6;6;6;3.5;22];


DNA.fitness = inf;
DNA.bestTrajectory = zeros(0,2);
[t,qss]=simulateDNA_mex(DNA,5,0.05);

animateDNA(DNA,t,qss);









