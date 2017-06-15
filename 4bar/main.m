clear all
close all
clc

h0 = [0 0]' ;
h1 = [0,1]';
h2 = [3 3]';
h3 = [4 0]';

a = h3(1)-h0(1);
b = h3(2)-h0(2);

L1 = norm(h1-h0);
L2 = norm(h2-h1);
L3 = norm (h3-h2);

phi1_0 = atan ((h1(2)-h0(2))/ (h1(1)-h0(1)));
phi2_0 = atan ((h2(2)-h1(2))/ (h2(1)-h1(1)));
phi3_0 = atan ((h3(2)-h2(2))/ (h3(1)-h2(1)));

syms phi1 phi2 phi3

q0 = [phi2_0,phi3_0]';
q = [phi2,phi3];


%Create constraint matrix D and its jacobian Dq
f1 = L1*cos(phi1)+L2*cos(phi2)+L3*cos(phi3) - a;
f2 = L1*sin(phi1)+L2*sin(phi2)+L3*sin(phi3) - b;
D = [f1;f2];
Dq = jacobian(D,q);
matlabFunction(Dq,'File','getDq')

%Initialize phi1
q = q0;
motion = zeros(36,3);

%Evaluation loop:
for m = 1:36
    phi1 = phi1_0+m*(1/36)*2*pi;
    
    %Newton-Rhapson loop:
    for n = 1:20
        %evaluate f:
        tic
        f = constraints(L1,L2,L3,phi1,a,b,q);
        normf = double(norm(f));
        if (normf <= 1e-3) 
            break;
        end;
        Dq = D_jacobian(q(1),q(2));
        delta_q = Dq\f;
        q = q - delta_q;
    end
    
    
    motion(m,:) = double([phi1,q']);
    if mod(m,5) == 0
        m
    end
end

x0 = h0(1);
y0 = h0(2);
x3 = h3(1);
y3 = h3(2);
phi1 = motion(:,1);
phi2 = motion(:,2);
phi3 = motion(:,3);

x1 = L1*cos(phi1);
x2 = x1+L2*cos(phi2);
y1 = L1*sin(phi1);
y2 = y1+L2*sin(phi2);


for i = 1:36
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

