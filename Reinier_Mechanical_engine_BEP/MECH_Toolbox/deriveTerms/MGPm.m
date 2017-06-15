function C4 = MGPm(in1,alpha,a,w,in5,t,in7)
%MGPM
%    C4 = MGPM(IN1,ALPHA,A,W,IN5,T,IN7)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    17-Oct-2016 18:51:21

H11 = in1(1,:);
H12 = in1(2,:);
com11 = in5(1,:);
com12 = in5(2,:);
theta1 = in7(3,:);
x1 = in7(1,:);
y1 = in7(2,:);
t2 = cos(theta1);
t3 = H12-com12;
t4 = sin(theta1);
t5 = H11-com11;
t6 = t2.*t3;
t7 = t4.*t5;
t8 = t3.*t4;
C4 = [-sin(alpha).*(H11+t8-x1-t2.*t5)-cos(alpha).*(-H12+t6+t7+y1),-H11-H12+t6+t7-t8+x1+y1+t2.*t5-a.*sin(t.*w)];