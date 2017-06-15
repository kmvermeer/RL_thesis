function Ft2 = MMtorsion(K,theta0,in3)
%MMTORSION
%    FT2 = MMTORSION(K,THETA0,IN3)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    17-Oct-2016 18:51:25

theta1 = in3(3,:);
theta2 = in3(6,:);
t2 = theta0.*2.0;
t3 = theta1.*2.0;
t4 = t2+t3-theta2.*2.0;
Ft2 = [0.0;0.0;K.*t4.*(-1.0./2.0);0.0;0.0;K.*t4.*(1.0./2.0)];