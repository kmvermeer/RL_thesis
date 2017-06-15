%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all; close all; clc; warning off; 

DNA = initializeDNA;

inc = [ 1 1 1 0 0 0 0 0 0 0  0 0 0 1 0 0 1;
        1 0 0 1 1 0 0 0 0 0  0 0 0 0 0 0 0;
        0 1 0 0 0 0 0 1 1 0  0 0 0 0 0 0 0;
        0 0 1 0 0 1 1 0 0 0  0 0 0 0 0 0 0;
        0 0 0 1 0 1 0 0 0 0  0 0 0 0 0 0 0;
        0 0 0 0 1 0 0 0 0 1  1 0 0 0 1 0 1;
        0 0 0 0 0 0 0 0 1 1  0 0 0 0 0 0 0;
        0 0 0 0 0 0 1 1 0 0  0 0 0 0 0 0 0;
        0 0 0 0 0 0 0 0 0 0  1 1 0 0 0 0 0;
        0 0 0 0 0 0 0 0 0 0  0 1 1 0 0 1 0;
        0 0 0 0 0 0 0 0 0 0  0 0 1 1 0 0 0;
        0 0 0 0 0 0 0 0 0 0  0 0 0 0 1 1 0];
    
DNA.incstr      = inc2str(inc);
DNA.edgelabel   = [ones(1,length(DNA.incstr)-1) 2];
DNA.Mpar        = [[NaN,NaN,NaN];rand(length(inc(:,1))-1,3)];
DNA.Hpar        = [[0;0],[0;0],[2;0],[6;2],[6;2],[4;0],[4;0],[6;-2],[6;-2],[8;0],[8;0],[8;-6],[6;-4],[0;-6],[6;2],[6;-4]];
DNA.Hpar(3:5,:) = 0;
DNA.Spar        = [6;4;6;2;2;50];


T           = 5;
h           = 0.05;
[t,qss]     = simulateDNA(DNA,T,h);
 animateDNA(DNA,t,qss);

getDOF(DNA)



