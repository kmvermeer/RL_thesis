function C2 = MMH(in1,in2,in3,in4)
%MMH
%    C2 = MMH(IN1,IN2,IN3,IN4)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    17-Oct-2016 18:51:20

H11 = in1(1,:);
H12 = in1(2,:);
com11 = in2(1,:);
com12 = in2(2,:);
com21 = in3(1,:);
com22 = in3(2,:);
theta1 = in4(3,:);
theta2 = in4(6,:);
x1 = in4(1,:);
x2 = in4(4,:);
y1 = in4(2,:);
y2 = in4(5,:);
t2 = cos(theta1);
t3 = H12-com12;
t4 = cos(theta2);
t5 = H12-com22;
t6 = sin(theta1);
t7 = H11-com11;
t8 = sin(theta2);
t9 = H11-com21;
C2 = [x1-x2+t2.*t7-t3.*t6-t4.*t9+t5.*t8;y1-y2+t2.*t3-t4.*t5+t6.*t7-t8.*t9];