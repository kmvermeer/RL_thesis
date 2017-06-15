%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function DOF = getDOF(DNA)

state = getInitialconditions(DNA).';

[~,Dk_j]      = getDk(0,state,DNA);

if ~any(any(isnan(Dk_j)))&& ~any(any(isinf(Dk_j)))
    nullDk_j = null(Dk_j);
    DOF = numel(nullDk_j(1,:));
else
    DOF=0;
end

