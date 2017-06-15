function [x1,y1,x2,y2] = hinge_positions(motion)
phi1 = motion(:,1);
phi2 = motion(:,2);
phi3 = motion(:,3);

x1 = L1*cos(phi1);
x2 = x1+L2*cos(phi2);
y1 = L1*sin(phi1);
y2 = y1+L2*sin(phi2);
end

