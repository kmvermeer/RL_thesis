%Code by K.M. Vermeer
%Code created on May 1st 2017
clear all
close all
%Initialising:
h1 = [0,0];
h2 = [2,0];
h3 = [1,2];
h4 = [3,2];

H = [h1;h2;h3;h4];

I = [1 1 0 0; 1 0 1 0; 0 1 0 1; 0 0 1 1];
M = zeros(size(I,1),4);

nM = size(I,1);
nH = size(I,2);


for n = 1:nM
    connections = find(I(n,:));
    h1 = H(connections(1),:);
    h2 = H(connections(2),:);
    new_link = [h1,h2];
    M(n,:) = new_link;
end

%Performing perturbations:

plot_mech(I,H,M)
pause
  
x=1;
y=2;

[I,H,M] = Ds_operator(I,H,M,2)
plot_mech(I,H,M)
axis([-5 5 -5 5])
pause
[I,H,M] = Ds_operator(I,H,M,3)
plot_mech(I,H,M)
axis([-5 5 -5 5])

pause
[I,H,M] = Ts_operator(I,H,M,6)
plot_mech(I,H,M)
axis([-5 5 -5 5])

pause


% link_list = [3,4,5,2,6,8];
% for i=1:length(link_list)
%     link=link_list(i);
%     [I,H,M] = Ds_operator(I,H,M,link);
%     clf
%     plot_mech(I,H,M)
%     axis auto
%     axis equal
%     pause
% end
% x=-1;
% y=4;
% link=3;
% [I,H,M] = D_operator(I,H,M,link,x,y);
% clf
% plot_mech(I,H,M)
% pause
% 
% x=2;
% y=0;
% link=2;
% [I,H,M] = T_operator(I,H,M,link,x,y);
% clf
% plot_mech(I,H,M) 
% pause
% 
% x=2;
% y=3;
% link=4;
% [I,H,M] = T_operator(I,H,M,link,x,y);
% clf
% plot_mech(I,H,M)
% pause

%Develop constraints

% M_phi = atan( (abs(M(:,4)-M(:,2)))./(abs(M(:,3)-M(:,1))));
% M_x = mean([M(:,1),M(:,3)],2);
% M_y = mean([M(:,2),M(:,4)],2);
% M_lengths = sqrt((M(:,3)-M(:,1)).^2+(M(:,4)-M(:,2)).^2);
% M = [M,M_x,M_y,M_phi,M_lengths];
% 
% % X0 = [M_x M_y M_phi]
% X0 = [M_x M_y zeros(length(M_x),1)];
% 
% X = X0;
% noConstr = size(H,1)*2
% D = ones(noConstr,1);
% for n = 1:size(H,1)
%     connected_masses = find(I(:,n));
%     xh = H(n,:)';
%     if ismember(1,connected_masses)
%         m = max(connected_masses);
%         Xm = X(m,:);
%         xc = [M_x(m);M_y(m)];
%         R = [cos(Xm(3)) -sin(Xm(3)) ; sin(Xm(3)) cos(Xm(3))];
%         xm = Xm(1:2)';
%         D(2*n-1:2*n) = xm - ( R*(xc - xh) + xh );
%     
%     else
%         m1 = min(connected_masses);
%         m2 = max(connected_masses);
%         
%         Xm1 = X(m1,:);
%         Xm2 = X(m2,:);
%        
%         xc1 = [M_x(m1);M_y(m1)];
%         xc2 = [M_x(m2);M_y(m2)];
%        
%         xm1 = Xm1(1:2)';
%         xm2 = Xm2(1:2)';
%         
%         D(2*n-1:2*n) = (R*(xh-xc1)+xm1)  -  (R*(xh-xc2)+xm2);
%     end    
%     
% end






















% D_ground:
% x - cos(theta)*len/2
% y - sin(theta)*len/2
% 
% number_of_hinges = size(H,1);
% D = zeros(number_of_hinges*2,1);
% for n = 1:number_of_hinges
%     connected_masses = find(I(:,n));
%     if ismember(1,connected_masses)
%         i = max(connected_masses);
%         constraint_x = M_x(i) - (cos(M_angles(i))*(M_x(i)-H(n,1))+H(n,1));
%         constraint_y = M_y(i) - (sin(M_angles(i))*(M_y(i)-H(n,2))+H(n,2));
%     else
%         m1 = connected_masses(1);
%         m2 = connected_masses(2);
%         constraint_x = M_x(m1)+cos(M_angles(m1))*(M_x(m1)-H(n,1)) ...
%         - (M_x(m2)-cos(M_angles(m2))*(M_x(m2)-H(n,1)));
%         constraint_y = M_y(m1)+sin(M_angles(m1))*(M_y(m1)-H(n,2)) ...
%         - (M_y(m2)+sin(M_angles(m2))*(M_y(m2)-H(n,2)));
%     end
%     D(2*n-1) = constraint_x;
%     D(2*n) = constraint_y;
% end
%     
%Try literally using the thesis method with rotational matrix R


