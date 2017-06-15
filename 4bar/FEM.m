clear all
close all
clc
tic

%Constants:
lr = 1;
evals = 100;


I =[1 1 0 0;
    1 0 1 0;
    0 1 0 1;
    0 0 1 1];
 
 H=[ 0   0;
    4.0000 1;
    0.5 1;
    3 3];
      
Htrans = H';
x0 = Htrans(:);

nM = size(I,1);
nH = size(I,2);
L = zeros(nM,1);

for i = 1:nM
    node = find(I(i,:));
    from = node(1);
    to = node(2);
    x1 = x0(2*from-1); y1 = (x0(2*from));
    x2 = x0(2*to-1); y2 = (x0(2*to));
    L(i) = sqrt((x2-x1)^2+(y2-y1)^2);
    if i == 1
        phi0 = atan2(y2-y1,x2-x1);
    end
end



%% Initializing matrices and values for FEA

dof = nH*2;
K = zeros(dof,dof);
G = K;
A = K;
H = K;
V = 1;
xout = zeros(evals, dof);
values = zeros(evals,1);
x = x0;

%%  FEA
 
for k = 1:evals
    dphi = (k/evals)*2*pi;
%     dphi = 0;
    x(5) = L(1)*cos(phi0+dphi);
    x(6) = L(1)*sin(phi0+dphi);
    V = 1;
    iter = 0;
    
    while V>1e-3 && iter<100
        K = zeros(dof,dof);
        G = K;
        A = K;
        H = K;
        V = 0;
        for i = 1:nM
            node = find(I(i,:));
            from = node(1);
            to = node(2);
            x1 = x(2*from-1); y1 = (x(2*from));
            x2 = x(2*to-1); y2 = (x(2*to));
            
            
            scatter = [2*from-1 2*from 2*to-1 2*to];
            Le = L(i);
            C= (x2 - x1) / Le;
            S =(y2 - y1) / Le;

            %Create ge_bar
            Ke_base =[C^2 C*S -C^2 -C*S;
                     C*S S^2 -C*S -S^2;
                    -C^2 -C*S C^2 C*S;
                    -C*S -S^2 C*S S^2];

            ge = Ke_base;
            ge_bar = zeros(dof,dof);
            ge_bar(scatter,scatter) = ge_bar(scatter,scatter)+ge;

            l = sqrt(x'*ge_bar*x);
            dL = l-Le;
            %Create ae_bar
            ae_bar = dL/Le*ge_bar*x;
            %Create ze_bar
            ze_bar = zeros(dof,dof);
            ze = [1 0 -1 0;
                  0 1 0 -1;
                  -1 0 1 0;
                  0 -1 0 1];

            ze_bar(scatter,scatter) = ze_bar(scatter,scatter)+ze;

            %Calculate current error in terms of elastic potential:
            Ve = 1/2*(l-Le)^2;

            %Update assemblies
            Ke = Ke_base;
            K(scatter,scatter) = K(scatter,scatter) + Ke;
            G = G + ge_bar;
            A  = A + ae_bar;
            H = H+(Le*ge_bar + (l-Le)*ze_bar);
            V = V+Ve;
        end

        dX = -pinv(H)*A ;
%         dX = linsolve(H,-A);
        dx = dX(:,1);
        x = x+lr*dx;
        x(1:4) = x0(1:4)';
        x(5) = L(1)*cos(phi0+dphi);
        x(6) = L(1)*sin(phi0+dphi);
        iter = iter+1;
        
    end
    xout(k,:) = x;
    values(k) = V;
%     plotx(x,I);
    
end
toc
for k = 1:evals
    x = xout(k,:);
    plotx(x,I)
end

% animate_motion(I,xout,nM,evals,values)


