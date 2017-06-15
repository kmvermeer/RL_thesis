function [I_new,H_new,M_new] = T_operator(I,H,M,link,x,y);

base_link = M(link,:)

%Determine new hinge location and add to H
base_link_hinges = find(I(link,:));
number_of_links = size (I,1);
number_of_hinges = size(I,2);
new_hing_col = zeros(number_of_links,1);

x_new = mean([base_link(1),base_link(3)])+x
y_new = mean([base_link(2),base_link(4)])+y
h_new = [x_new,y_new];
H_new = vertcat(H,h_new);

%Determine closes hinge
H_for_closest = H;
H_for_closest(min(base_link_hinges),:) = [];
H_for_closest(max(base_link_hinges)-1,:) = [];

closest_hinge = dsearchn(H_for_closest,h_new);
hing_no_in_closestH = ismember(H_new,H_for_closest(closest_hinge,:),'rows');
closest_hinge = find(hing_no_in_closestH,1);


%Create new rows for links in I
new_bar1_base_row = zeros(1,number_of_hinges);
new_bar1_base_row(base_link_hinges(1))=1;
new_bar1_row = [new_bar1_base_row,1];

new_bar2_base_row = zeros(1,number_of_hinges);
new_bar2_base_row(base_link_hinges(2))=1;
new_bar2_row = [new_bar2_base_row,1];

replacement_link_base_row = zeros(1,number_of_hinges);
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

