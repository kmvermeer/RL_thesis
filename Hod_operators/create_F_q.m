function [F,q_symb,q,q0] = create_F_q(I,H,M)

    %Setting number of elements and base lengths
    nM = size(M,1);
    nH = size(H,1);
    M_distances = [M(:,3)-M(:,1) M(:,4)-M(:,2)];
    L = sqrt( M_distances(:,1).^2+M_distances(:,2).^2 );
    
    %Determine initial values
    X0 = H(1,1);
    Y0 = H(1,2);
    Xend = H(2,1);
    Yend = H(2,2);
    phi_ground = atan2((Yend-Y0),(Xend-X0));
    
    %Creating symbolic values for q
    xn = sym('x%d',[1,nH]);
    yn = sym('y%d',[1,nH]);
    phin = sym('phi%d',[1,nM]);
    phin(1) = phi_ground;
    xn(1) = X0;
    xn(2) = Xend;
    yn(1) = Y0;
    yn(2) = Yend;
    q = [phin(2:end),xn(3:end),yn(3:end)];
    q_symb = q;
    
    %Initial values...
    x0 = H(3:end,1)';
    y0 = H(3:end,2)';
    phi0 = zeros(1,nM-1);
    
    for i = 2:nM
        hinges = find(I(i,:));
        fr = hinges(1);
        to = hinges(2);
        y = H(to,2)- H(fr,2);
        x = H(to,1)-H(fr,1);
        phi0_new = atan2(y,x);
        phi0(i-1) = phi0_new;
    end
    q0 = [phi0,x0,y0];
    
    %Determine constraint function based the fact that every
    %hinge constraints the x and y location of the two elements
    %it links to be equal where they meet.
    
    F=[];
        for i = 1:nM
            hinges = find(I(i,:));
            fr = hinges(1);
            to = hinges(2);

            x0 = xn(fr);
            y0 = yn(fr);
            x1 = xn(to);
            y1 = yn(to);

            phi = phin(i);
            
            R = [cos(phi);sin(phi)];
            Xfr = [x0;y0];
            Xto = [x1;y1];
            l = L(i);
            f = Xfr+l*R-Xto;
            F = [F;f];
        end
        F
        phi0
end
