
%simulateDNA - computes the states of the mechanism represented by DNA. The
%mex-version of this function is used in the EA. When compiling the
%functions getCompoints.m and getDk.m should be checked not to contain
%getInc_mex.

function [t,qss,flag] = simulateDNA(DNA,T,h)

x0  = getInitialconditions(DNA);   
nx0 = length(x0)/2;

[t,qss,flag] = rk4(@eom,[0 T],x0,h,nx0,DNA);

