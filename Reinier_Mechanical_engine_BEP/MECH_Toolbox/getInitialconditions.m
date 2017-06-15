%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



function x0 = getInitialconditions(DNA)

comPoints = getCompoints(DNA);          %body boundaries and com
nM = numel(comPoints(:,1));
  
x0 = zeros(1,3*nM);
xd0 = zeros(1,3*nM);
for k =1:nM
    x0(k*3-2) = comPoints(k,1);
    x0(k*3-1) = comPoints(k,2);
end

x0 = [x0 xd0];