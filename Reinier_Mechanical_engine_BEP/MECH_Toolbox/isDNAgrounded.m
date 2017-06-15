% isDNAgrounded(DNA) checks if the mechanisms is connect to ground by hinge
%
% Input : A DNA matrix
%
% Output: 1 if at least one mass is connected to a ground with a hinge.
%         0 if no masses are connected to a ground with a hinge
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%   Last modified: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function TF = isDNAgrounded(DNA)

if ~isempty(DNA.incstr(DNA.edgelabel==1))
    incH     = DNA2inc(DNA,'H');        %Create incidence matrix of hinges
    nGrounds = sum(incH(1,:));          %Count the number of grounds
    
    if nGrounds >= 1
        TF = 1;
    else
        TF = 0;
    end
    
else
    TF = 0;
end






