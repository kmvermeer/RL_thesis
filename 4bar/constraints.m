function f = constraints(L1,L2,L3,phi1,a,b,x)
    phi2 = x(1);
    phi3 = x(2);
    f1 = L1*cos(phi1)+L2*cos(phi2)+L3*cos(phi3) - a;
    f2 = L1*sin(phi1)+L2*sin(phi2)+L3*sin(phi3) - b;
    f = double([f1;f2]);
end