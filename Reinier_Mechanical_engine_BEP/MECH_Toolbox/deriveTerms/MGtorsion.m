function Ft1 = MGtorsion(K,theta0,in3)
%MGTORSION
%    FT1 = MGTORSION(K,THETA0,IN3)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    17-Oct-2016 18:51:25

theta1 = in3(3,:);
Ft1 = [0.0;0.0;K.*(theta0.*2.0-theta1.*2.0).*(1.0./2.0)];