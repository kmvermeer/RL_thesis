function [I_new,H_new,M_new] = T_operator(I,H,M,link)

base_link = M(link,:);
base_vec = [M(link,3)-M(link,1) ; M(link,4)-M(link,2)];

%Determine new hinge location and add to H
base_link_hinges = find(I(link,:));
nM = size (I,1);
nH = size(I,2);
new_hing_col = zeros(nM,1);

%Formulas to find COM x and y for a mass
get_xs = @(mass) mean([M(mass,1),M(mass,3)]);
get_ys = @(mass) mean([M(mass,2),M(mass,4)]);

%Determine unit link perpendicular to base link
x_com = get_xs(link);
y_com = get_ys(link);
L = norm(base_vec);
unit_link = base_vec/L;
new_unit_link = null(unit_link');

%Determine which links are neighbouring the base link and where their
%center of gravity lies
neighbour_links = find(I(:,base_link_hinges));
neighbour_links = mod(neighbour_links,nM);
neighbour_links(neighbour_links == 0) = nM;
neighbour_links(neighbour_links == link) = [];

x_neighbours = mean(get_xs(neighbour_links));
y_neighbours = mean(get_ys(neighbour_links));

%If angle from base link's COM is close to the unit vector perp to the
%link, we choose opposing side of the base link for the new point.
com2neighbours = [x_neighbours-x_com;y_neighbours-y_com];
get_angle = @(u,v) dot(u,v)/(norm(u)*norm(v));
angle = acos(get_angle(com2neighbours,new_unit_link));
if angle<(pi/2)
    direction = -1;
else
    direction = 1;
end
newpos = [x_com;y_com]+direction*L*new_unit_link;

H_new = vertcat(H,newpos');

%Determine closes hinge
cross_list = [0 0 0];
drops = [min(base_link_hinges),max(base_link_hinges),size(H_new,1)];

while numel(cross_list)>0
    H_for_closest = H_new;
    H_for_closest(drops,:) = [];
    
    closest_hinge = dsearchn(H_for_closest,newpos');
    hing_no_in_closestH = ismember(H_new,H_for_closest(closest_hinge,:),'rows');
    closest_hinge = find(hing_no_in_closestH,1);
    
    %Check for crosses
    new_link = [H_new(closest_hinge,:),H_new(end,:)];
    cross_list = detect_crossing(I,H,link,new_link);
    cross_list
    %If corssing occurs, delete currently selected hinge from search space
    if numel(cross_list)>0
        drops = [drops,closest_hinge];
    end 
end


%Create new rows for links in I
new_bar1_base_row = zeros(1,nH);
new_bar1_base_row(base_link_hinges(1))=1;
new_bar1_row = [new_bar1_base_row,1];

new_bar2_base_row = zeros(1,nH);
new_bar2_base_row(base_link_hinges(2))=1;
new_bar2_row = [new_bar2_base_row,1];

replacement_link_base_row = zeros(1,nH);
replacement_link_base_row(closest_hinge)=1;
replacement_link = [replacement_link_base_row,1];

%Construct I
I_interim = [I,new_hing_col];
I_interim(link,:) = replacement_link;
I_new = vertcat(I_interim,new_bar1_row,new_bar2_row);

%Update M
M_replace = [H_new(closest_hinge,:),H_new(end,:)];
M_new1 = [H_new(base_link_hinges(1),:),H_new(end,:)];
M_new2 = [H_new(base_link_hinges(2),:),H_new(end,:)];
M(link,:) = M_replace;
M_new = vertcat(M,M_new1,M_new2);
end

