function [I_new,H_new,M_new] = Ds_operator(I,H,M,link)
nM = size(I,1);
% nH = size(I,2);

% base_link = M(link,:);
base_vec = [M(link,3)-M(link,1) ; M(link,4)-M(link,2)];

%Creating new incidence matrix
base_link_hinges = find(I(link,:));
number_of_links = size (I,1);
number_of_hinges = size(I,2);
new_hing_col = zeros(number_of_links,1);

new_bar1_base_row = zeros(1,number_of_hinges);
new_bar1_base_row(base_link_hinges(1))=1;
new_bar1_row = [new_bar1_base_row,1];

new_bar2_base_row = zeros(1,number_of_hinges);
new_bar2_base_row(base_link_hinges(2))=1;
new_bar2_row = [new_bar2_base_row,1];

I_interim = [I,new_hing_col];
I_new = vertcat(I_interim,new_bar1_row,new_bar2_row);

get_xs = @(mass) mean([M(mass,1),M(mass,3)]);
get_ys = @(mass) mean([M(mass,2),M(mass,4)]);

x_com = get_xs(link);
y_com = get_ys(link);
L = norm(base_vec);
unit_link = base_vec/L;
new_unit_link = null(unit_link');

neighbour_links = find(I(:,base_link_hinges));
neighbour_links = mod(neighbour_links,nM);
neighbour_links(neighbour_links == 0) = nM;
neighbour_links(neighbour_links == link) = [];

x_neighbours = mean(get_xs([neighbour_links]));
y_neighbours = mean(get_ys([neighbour_links]));


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

M_new1 = [H_new(base_link_hinges(1),:),H_new(end,:)];
M_new2 = [H_new(base_link_hinges(2),:),H_new(end,:)];

M_new = vertcat(M,M_new1,M_new2);
end

