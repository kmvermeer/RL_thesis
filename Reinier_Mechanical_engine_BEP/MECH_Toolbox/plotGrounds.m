% plotGrounds(DNA) plots all the grounds of a mechanism.
%
%   Input:  DNA
%   Output: figure with all grounds

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 2-07-2015                                              %
%   Last modified: 2-07-2015                                              %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function []=plotGrounds(DNA)
hold on

cdata       = [0.2 0.2 0.2];

[xOutline,yOutline,xSmallCircle,ySmallCircle] = getGroundOutline(DNA);

for k = 1:numel(xOutline)
    fill(xOutline{k},yOutline{k},cdata);
    fill(xSmallCircle{k},ySmallCircle{k},'w','Linewidth',2)
end










