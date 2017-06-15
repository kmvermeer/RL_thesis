function C3_q = MGP_q(in1,alpha,in3,in4)
%MGP_Q
%    C3_Q = MGP_Q(IN1,ALPHA,IN3,IN4)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    17-Oct-2016 18:51:21

H11 = in1(1,:);
H12 = in1(2,:);
com11 = in3(1,:);
com12 = in3(2,:);
theta1 = in4(3,:);
t2 = cos(alpha);
t3 = sin(alpha);
t4 = cos(theta1);
t5 = H12-com12;
t6 = sin(theta1);
t7 = H11-com11;
C3_q = [t3,-t2,-t2.*(t4.*t7-t5.*t6)-t3.*(t4.*t5+t6.*t7)];
