%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function [x1,y1,x2,y2,x3,y3]=getComOutline(p)

resolution = 0.1;

t1 = 0:resolution:pi/2;
t2 = pi:resolution:3/2*pi;
t3 = 0:resolution:2*pi;

x1 = 0.1*cos(t1)+p(1);
y1 = 0.1*sin(t1)+p(2);
x2 = 0.1*cos(t2)+p(1);
y2 = 0.1*sin(t2)+p(2);
x3 = 0.1*cos(t3)+p(1);
y3 = 0.1*sin(t3)+p(2);

x1 = [p(1) x1];
y1 = [p(2) y1];

x2 = [p(1) x2];
y2 = [p(2) y2];


% fill(x3,y3,'w')
% plot(x3,y3,'k')
% fill(x1,y1,'k')
% fill(x2,y2,'k')

end%Function

