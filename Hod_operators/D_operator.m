function [I_new,H_new,M_new] = D_operator(I,H,M,link,x,y);

base_link = M(link,:);

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


x_new = mean([base_link(1),base_link(3)])+x;
y_new = mean([base_link(2),base_link(4)])+y;
h_new = [x_new,y_new];
H_new = vertcat(H,h_new);

M_new1 = [H_new(base_link_hinges(1),:),H_new(end,:)];
M_new2 = [H_new(base_link_hinges(2),:),H_new(end,:)];

M_new = vertcat(M,M_new1,M_new2);
end

