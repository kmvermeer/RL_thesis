%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  
%  Runge Kutta 4th order


function [tout, yout, flag] = rk4(F,tspan,y0,h,nx0,DNA)

flag    = 1;
t0      = tspan(1);
tfinal  = tspan(2);
t       = t0;
y       = y0(:);

tlength = numel(0:h:tfinal);
ylength = numel(y);

tout        = zeros(tlength,1); 
yout        = zeros(tlength,ylength);
yout(1,:)   = y0.';

% Main loop 
for k = 2:length(tout)
    
    %Runge-Kutta 4th order function evaluations
    s1 = F(t,y,nx0,DNA);
    s2 = F(t+(h/2),y+(h/2)*s1,nx0,DNA);
    s3 = F(t+(h/2),y+(h/2)*s2,nx0,DNA);
    s4 = F(t+h,y+h*s3,nx0,DNA);
    ynew = y +(h/6)*(s1+2*s2+2*s3+s4);
    tnew = t + h;
    
    %Update variables
    y = ynew;
    t = tnew;
    
    tout(k)   = t;
    yout(k,:) = y.';
    
    dyout = yout(k,:)-yout(k-1,:);
    
    %Check for NAN and for large derivatives
    if any(isnan(yout(:)))||any(dyout(1:end/2)>10) 
        flag = 0;
        break
    end
end
% end





