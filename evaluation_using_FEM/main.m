clear all
close all
clc
tic

%% Constants and Settings:
lr = 1;
evals = 500;
rotate = 2*pi;
turnme = 3;

%% Initialize structure:
% [I,H] = random_init(1);                   %Uncomment for random structure
[I,H] = demo_structures(8);                 %Uncomment for deme structure% 

Htrans = H';
x0 = Htrans(:);
nM = size(I,1);
nH = size(I,2);
L = zeros(nM,1);

%% Setting free and fixed elements:
cons_to_1 = get_connections(I,1,'hinge');
if length(cons_to_1) == 1
    input_link = cons_to_1;
else
    cons_to_1(cons_to_1 == 1) = [];
    input_link = min(cons_to_1);
end

fixme = [1,2];
fixed = [fixme,turnme];
nodes = 1:1:2*nH;
fixnodes = sort([2*fixed-1 2*fixed]);
freenodes = nodes;
freenodes(fixnodes) = [];

%% Determining initial lenghts and angle phi0
for i = 1:nM
    node = get_connections(I,i,'bar');
    from = node(1);
    to = node(2);
    x1 = x0(2*from-1); y1 = (x0(2*from));
    x2 = x0(2*to-1); y2 = (x0(2*to));
    L(i) = sqrt((x2-x1)^2+(y2-y1)^2);
    if i == input_link
        phi0 = atan2(y2-y1,x2-x1);
    end
end

%% Performing FEA 
tic
[xout,values]=FEA(I,x0,phi0,L,input_link,freenodes,evals,rotate);
toc

%% Determine scores and display them
if sum(isnan(values)) == 0 && size(xout,1)>5
    [final_score,id_max,straightness_score_list,length_straight_sections]=... 
        trajectory_analysis(xout,values,I,x0,true);
    scores = straightness_score_list.*length_straight_sections;
    disp('Straightness_scores')
    disp(straightness_score_list)
    disp('Length scores')
    disp(length_straight_sections)
    disp('Total scores')
    disp(scores)
    disp(length_straight_sections(id_max-2))
    screenshots = animate_motion(I,xout,nM,values);
    plotx(x0,I)
else
    final_score = 0;
    disp('Infeasible design')
end

