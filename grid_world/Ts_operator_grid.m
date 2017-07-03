function [I_new,H_new] = Ts_operator_grid(I,H,link,gridxy)
n = sqrt(size(gridxy,1));

%Determine new hinge location and add to H
base_link_hinges = find(I(link,:));
base_vec = diff(H(base_link_hinges,:))';
nM = size (I,1);
nH = size(I,2);
new_hing_col = zeros(nM,1);

%Formulas to find COM x and y for a mass
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

%Determine closes hinge
cross_list = [0 0 0];
drops = [min(base_link_hinges),max(base_link_hinges),size(H_new,1)];
H_new_base = H_new;
H_new_base(drops,:) = [];

while numel(cross_list)>0
    H_for_closest = H_new;
    H_for_closest(drops,:) = [];
    
    %FIX: if no non-crosser can be found, just select closest.
    if size(H_for_closest,1)==0
        closest_hinge = dsearchn(H_new_base,newpos');
        break
    end
    
    closest_hinge = dsearchn(H_for_closest,newpos');
    hing_no_in_closestH = ismember(H_new,H_for_closest(closest_hinge,:),'rows');
    closest_hinge = find(hing_no_in_closestH,1);
    
    %Check for crosses
    new_link = [H_new(closest_hinge,:),H_new(end,:)];
    cross_list = detect_crossing(I,H,link,new_link);
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

end

