function Dx = D_jacobian(phi2,phi3)
    d1 =  [ -2*sin(phi2), -5^(1/2)*sin(phi3)];
    d2 = [  2*cos(phi2),  5^(1/2)*cos(phi3)];
    Dx = double([d1;d2]);
end
    