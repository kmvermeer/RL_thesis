function [I_new,H_new] = Ds_operator_grid(I,H,link,gridxy)
nM = size(I,1);
n = sqrt(size(gridxy,1));


%Creating new incidence matrix
base_link_hinges = get_connections(I,link,'bar');
base_vec = diff(H(base_link_hinges,:))';
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

%Pinpointing the new point
get_mean_xy = @(mass) mean(H(get_connections(I,mass,'bar'),:),1);

xy_com = get_mean_xy(link);
x_com = xy_com(1);
y_com = xy_com(2);
L = norm(base_vec);
unit_link = base_vec/L;
new_unit_link = null(unit_link');

neighbour_links = find(I(:,base_link_hinges));
neighbour_links = mod(neighbour_links,nM);
neighbour_links(neighbour_links == 0) = nM;
neighbour_links(neighbour_links == link) = [];
COMs = [];

for q = 1:length(neighbour_links)
    COM = get_mean_xy(neighbour_links(q));
    COMs = [COMs;COM];
end
COM_neighbours = mean(COMs,1);
x_neighbours = COM_neighbours(1);
y_neighbours = COM_neighbours(2);

com2neighbours = [x_neighbours-x_com;y_neighbours-y_com];
get_angle = @(u,v) dot(u,v)/(norm(u)*norm(v));
angle = acos(get_angle(com2neighbours,new_unit_link));
if angle<(pi/2)
    direction = -1;
else
    direction = 1;
end
newpos = [x_com;y_com]+direction*L*new_unit_link;
newpos = round(newpos);
if newpos(1)>n
   newpos(1) = n;
elseif newpos(1)<1
    newpos(1) = 1;
end
if newpos(2) > n
    newpos(2) = n;
elseif newpos(2)<1
    newpos(2) = 1;
end

H_new = vertcat(H,newpos');
end

