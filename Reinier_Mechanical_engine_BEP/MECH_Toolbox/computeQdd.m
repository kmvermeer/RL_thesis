%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%




function qdd = computeQdd(t,state,DNA)

nX  = length(state)/2;              %Get the number of coordinates
Xd = state(nX+1:end);               %Get the velocity vector
 
[~,Dq,Dqq,Dt,Dqt,Dtt] = getDk(t,state,DNA);  %Get Jacobian and convective accelerations

G = 2*Dqt+Dqq+Dtt;

F = getForces(t,state,DNA);

mass    = DNA.Mpar(2:end,3);                       
inertia = (1/12)*mass*1;
nM      = numel(mass);  



Mij = zeros(nM*3);                                   %Build mass matrix
for k = 1:nM
    Mij(k*3-2,k*3-2) = mass(k);
    Mij(k*3-1,k*3-1) = mass(k);
    Mij(k*3,k*3)     = inertia(k);
end
  

sDq  = size(Dq);
 
Mass = [Mij     Dq.';
        Dq    zeros(sDq(1))];

RHS = [F;-G];

eomLHS = [  eye(length(Xd))                     zeros(length(Xd),length(Mass));
            zeros(length(Xd),length(Mass)).'    Mass];
 
eomRHS = [Xd;RHS];

qdd = eomLHS\eomRHS;

