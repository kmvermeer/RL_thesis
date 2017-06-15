% isDNAconnected(DNA) checks if the mechanism is fully connected.
%
% Input : A DNA matrix
%
% Output: 1 if all masses are interconnected by hinges. 
%         0 if not all masses are interconnected by hinges.
%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %           
%   Original Date: 30-06-2015                                             %
%   Last modified: 30-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function TF = isDNAconnected(DNA)


eH = DNA2edgelist(DNA,'H');
eP = DNA2edgelist(DNA,'P');
ePm = DNA2edgelist(DNA,'Pm');

el = [eH eP ePm];
 
if ~isempty(el)
    incH         = zeros(max(max(el)),length(el(1,:)));
    
    for k = 1:length(el(1,:))
        incH(el(:,k),k) = 1;
    end%For
    
else
    incH = [];
end%If

incS     = DNA2inc(DNA,'S');
sincH    = size(incH);
sincS    = size(incS);

incH(:,incH(1,:)==1) = [];      %Delete edges that connect grounds
incH(1,:) = [];                 %Delete the ground

if sincH(1)<sincS(1)
    TF = 0;
    
elseif isempty(incH)&&sincH(1)<=2
    TF = 1;

else
    adjH    = inc2adj(incH);        %Create adjacency matrix from incidence
    TF      = isConnected(adjH);    %Test for connectivity
end
    



