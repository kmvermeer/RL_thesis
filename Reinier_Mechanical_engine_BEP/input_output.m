
clear all; close all; clc
   
k=10;

DNA = initializeDNA;

inc = [ 1   0   0   0     1   ;
        1   1   0   0     0   ;
        0   1   1   0     0   ;
        0   0   1   1     0   ;
        0   0   0   1   1     ]; 
    
DNA.incstr      = inc2str(inc);
DNA.edgelabel   = [4 1 1 1  3];

DNA.Mpar        = [[NaN,NaN,NaN];rand(length(inc(:,1))-1,3)];

DNA.Hpar = [[0;-1],[0;-2],[0;-3]];
DNA.Hpar(3,:) = k;
DNA.Hpar(4:5,:)=0;
DNA.Ppar(:,1)  = [0,-4,pi/2].';
DNA.Pmpar(:,1) = [0,0,0,1,2].';            % [x-coordinate y-coordinate angle amplitude frequency]


DNA.fitness = inf;
DNA.bestTrajectory = zeros(0,2);
[t,qss]=simulateDNA_mex(DNA,5,0.05);

animateDNA(DNA,t,qss);









