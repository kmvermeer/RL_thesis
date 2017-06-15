%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function qss = newton_raphson(t,qss,nx0,DNA)

maxiter = 1000;
tol = 1e-12;

q_tilde = qss(1:nx0);
qd_tilde = qss(nx0+1:nx0*2);

iter = 0;
% F = constraint(q_tilde);

D = getDk(t,qss,DNA); %constraint vector


while (max(abs(D))>tol) && (iter<maxiter) 
    
%     J = constraintd(q_tilde);
%     F = constraint(q_tilde);
[D,Dk] = getDk(t,qss,DNA);
%     F = getDk(qss,DNA);
       
    invJ = Dk.'/(Dk*Dk.');

    q_new = q_tilde - invJ*D;
    
    q_tilde = q_new;
    iter = iter+1;
    
    qss(1:nx0) = q_new;

end
 
% F = constraintd(qss)*qd_tilde;

[~,Dk,~,Dt] = getDk(t,qss,DNA);
Dd = Dk*qd_tilde+Dt;


iter = 0;

while (max(abs(Dd))>tol) && (iter<maxiter) 
    
%     J   = constraintd(qss(1:nx0));
[~,Dk,~,Dt] = getDk(t,qss,DNA);
    Dd   = Dk*qd_tilde+Dt;
           
    invJ = Dk.'/(Dk*Dk.');
        
    qd_new = qd_tilde - invJ*Dd;
    qd_tilde = qd_new;

    iter = iter+1;
    
    qss(nx0+1:nx0*2) = qd_new;

end





