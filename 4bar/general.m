clear all
close all
clc

h0 = [0 0]' ;
h1 = [1,3]';
h2 = [3 3]';
h3 = [4 1]';
H = [h0';h1';h2';h3'];

nH = size(H,1);
phi_syms = sym('phi%d',[1,nH-1]);

%Detecting ground points:
ground1 = 1;
ground2 = 4;
g1 = H(ground1,:);
g2 = H(ground1,:);

x_ground = g2(1)-g1(1);
y_ground = g2(2)-g1(2);

%Lengths and initial angles
L = zeros(nH-1,1);
phi_0 = zeros(nH-1,1);
for i = 1:(nH-1)
    L(i) = norm(H(i+1,:)-H(i,:));
    phi_0(i) = atan( (H(i+1,2)-H(i,2)) / (H(i+1,1)-H(i,1)) );
end


%S
q0 = phi_0(2:end,:);
q = phi_syms(2:3);


%Create constraint matrix D and its jacobian Dq

I = [1 1 0 0;
    0 1 1 0 ;
    0 0 1 1];
nM = size(I,1);

for i = 1:nM
    conn = find(I(i,:));
    from = conn(1);
    to = conn(2);
    f1 = x(from)+L(i)*cos(phi(from))-x(to);
    f2 = y(from)+L(i)*sin(phi(from))-y(to);
    F(i:
end


f1 = 0;
for i=1:(nH-1)
    f1_sub= L(i)*cos(phi_syms(i));
    f1 = f1+f1_sub;
end
f1 = f1 - x_ground;

f2 = 0;
for i=1:(nH-1)
    f2_sub= L(i)*sin(phi_syms(i));
    f2 = f2+f2_sub;
end
f2 = f2 - y_ground;
D = [f1;f2];
Dq = jacobian(D,q);
matlabFunction(Dq,'File','getDq')

%Initialize phi1
q = q0;


motion = zeros(36,3);

%Evaluation loop:
for m = 1:36
    phi1 = phi_0(1)+m*(1/36)*2*pi;
    
    %Newton-Rhapson loop:
    for n = 1:20
        %evaluate f:
        tic
        f = constraints(L(1),L(2),L(3),phi1,x_ground,y_ground,q);
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

x1 = L(1)*cos(phi1);
x2 = x1+L(2)*cos(phi2);
y1 = L(1)*sin(phi1);
y2 = y1+L(2)*sin(phi2);


for i = 1:36
    grid on
    plot([g1(1),x1(i),x2(i),g2(2),g1(2),y1(i),y2(i),g2(2)],'-*')
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

