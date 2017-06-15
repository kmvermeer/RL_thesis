function dFdQ = getdFdQ(in1)
%GETDFDQ
%    DFDQ = GETDFDQ(IN1)

%    This function was generated by the Symbolic Math Toolbox version 7.1.
%    15-May-2017 15:49:53

phi2 = in1(:,1);
phi3 = in1(:,2);
phi4 = in1(:,3);
phi5 = in1(:,4);
phi6 = in1(:,5);
t2 = sqrt(1.0e1);
t3 = sqrt(5.0);
t4 = sqrt(8.5e1);
dFdQ = reshape([0.0,0.0,-t2.*sin(phi2),t2.*cos(phi2),0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-t3.*sin(phi3),t3.*cos(phi3),0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,t4.*sin(phi4).*(-1.0./2.0),t4.*cos(phi4).*(1.0./2.0),0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,sin(phi5).*(-5.0./2.0),cos(phi5).*(5.0./2.0),0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,sin(phi6).*(-5.0./2.0),cos(phi6).*(5.0./2.0),0.0,0.0,-1.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0,0.0,-1.0,0.0,-1.0,0.0,0.0,0.0,0.0,-1.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,-1.0,0.0,-1.0,0.0,-1.0],[12,11]);