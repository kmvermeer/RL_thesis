%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function popDNA = preAllocateDNA(popSize)

%preAllocateDNA - preallocation of DNA structures
%
%   Input: collection size NxN: [N,N]
%   Ouput: collection of NxN empty DNA structures. Each DNA strand is a
%   struct of the form: 
%
%            incstr: []
%         edgelabel: []
%              Mpar: []
%              Hpar: []
%              Spar: []
%           fitness: []
%    bestTrajectory: []
%

fieldnames = {'incstr','edgelabel','Mpar','Hpar','Spar','Ppar','Pmpar','fitness','bestTrajectory'};
emptycells = repmat(cell(1),1,numel(fieldnames));
entries = {fieldnames{:};emptycells{:}};
emptyDNAstrand = struct(entries{:});

popDNA = repmat(emptyDNAstrand,popSize(1),popSize(2));

 