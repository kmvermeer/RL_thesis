%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function mat = str2inc(str)

mS  = max(str);
M   = incPattern2(mS);
mat = M(:,str);