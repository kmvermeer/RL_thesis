clear all
close all
clc

h0 = [1, 0]' ;
h1 = [0,1]';
h2 = [4 2]';
h3 = [4 0]';

a = h3(1)-h0(1);
b = h3(2)-h0(2);

L1 = norm(h1-h0);
L2 = norm(h2-h1);
L3 = norm (h3-h2);


phi1_0 = atan2 ((h1(2)-h0(2)), (h1(1)-h0(1)));
phi2_0 = atan2 ((h2(2)-h1(2)),(h2(1)-h1(1)));
phi3_0 = atan2 ((h3(2)-h2(2)), (h3(1)-h2(1)));


% q0 = [phi1_0;phi2_0;phi3_0];
syms phi1 phi2 phi3 x1 x2 x3 y1 y2 y3

x0 = h0(1);
y0 = h0(2);

x1_0 = h1(1);
y1_0 = h1(2);

x2_0 = h2(1);
y2_0 = h2(2);

x3 = h3(1);
y3 = h3(2);

q0 = [x1_0, y1_0,x2_0,y2_0,phi1_0,phi2_0,phi3_0];
q = [x1,y1,x2,y2,phi1,phi2,phi3];


%Create constraint matrix D and its jacobian Dq

f1 = x0+L1*cos(phi1)-x1;
f2 = y0+L1*sin(phi1)-y1;
f3 = x1+L2*cos(phi2)-x2;
f4 = y1+L2*sin(phi2)-y2;
f5 = x2+L3*cos(phi3)-x3;
f6 = y2+L3*sin(phi3)-y3;
F = [f1;f2;f3;f4;f5;f6];

dFdQ = jacobian(F,q);

% f1 = L1*cos(phi1)+L2*cos(phi2)+L3*cos(phi3) - a;
% f2 = L1*sin(phi1)+L2*sin(phi2)+L3*sin(phi3) - b;
% F = [f1;f2];

matlabFunction(F,'File','getF')
matlabFunction(dFdQ,'File','getdFdQ')


%% Loopings
%Evaluation loop:
error = 1;
q = q0;
motion = zeros(100,numel(q));
errorvec = [];
for n=1:100
    %Set input angle
    phi1= phi1_0+(n-1)*(1/100)*2*pi;
    q(5) = phi1;
    iter = 0;
    while error>1e-6 && iter<1000
        x1 = q(1);
        y1 = q(2);
        x2 = q(3);
        y2 = q(4);
        phi1 = q(5);
        phi2 = q(6);
        phi3 = q(7);
        
        %Determine constraint value f and according error
        f = getF(phi1,phi2,phi3,x1,x2,y1,y2);
        error = norm(f);
        %Determine jacobian of F: dFdQ
        dFdQ = getdFdQ(phi1,phi2,phi3);
        %Solve f + dFdQ*dq = 0 for dq
        dq = -dFdQ\f;
        q = q+dq';        
%         track_q = [track_q;q];
        iter = iter+1;
    end
    errorvec = [errorvec;error];
    error = 1;
     motion(n,:) = q;
end


x0 = h0(1);
y0 = h0(2);
x3 = h3(1);
y3 = h3(2);
x1 = motion(:,1);
y1 = motion(:,2);
x2 = motion(:,3);
y2 = motion(:,4);



for i = 1:n
    grid on
    plot([x0(1),x1(i),x2(i),x3],[h0(2),y1(i),y2(i),y3],'-*')
    axis([-5 5 -5 5])
    M(i) = getframe;
end



% 
% for a=1:36
%     X(3) = X(3)+10
%     
%     D = getD(L1,L2,X)
% 
%     
% 
% 
% 
% 
% 
% end
% plot([h0(1),h1(1),h2(1),h3(1)],[h0(2),h1(2),h2(2),h3(2)],'-*')

