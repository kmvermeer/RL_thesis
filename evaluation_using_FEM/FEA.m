function [xout,values]=FEA(I,x0,phi0,L,input_link,freenodes,evals,total_rotation)
    %% Initializing matrices and values for FEA
    nH = size(I,2);
    nM = size(I,1);
    dof = nH*2;
    K = zeros(dof,dof);
    G = K;
    A = K;
    Hessian = K;
    V = 1;
    xout.right = zeros(evals, dof);
    xout.left = xout.right;
    values.right = zeros(evals,1);
    values.left = values.right;
    x = x0;
    angle = phi0;
    dphi = total_rotation/evals;

    input_direction = 1;
    reverse = 0;
    err = 1e-4;
    list_of_angles = linspace(0,2*pi,evals);
    k = 1;
    infeasible_domain = 0;
    
    while k<evals && not(infeasible_domain == 1 && reverse == 1)
    %     dphi = 0;

        x(5) = L(input_link)*cos(angle);
        x(6) = L(input_link)*sin(angle);
        V = 1;
        iter = 0;

        while V>err && iter<100
            K = zeros(dof,dof);
            A = K;
            Hessian = K;
            V = 0;
            for i = 1:nM
                node = get_connections(I,i,'bar');
                from = node(1);
                to = node(2);
                x1 = x(2*from-1); y1 = (x(2*from));
                x2 = x(2*to-1); y2 = (x(2*to));


                scatter = [2*from-1 2*from 2*to-1 2*to];
                Le = L(i);
                C= (x2 - x1) / Le;
                S =(y2 - y1) / Le;

                %Create ge_bar
                Ke_base =[C^2 C*S -C^2 -C*S;
                         C*S S^2 -C*S -S^2;
                        -C^2 -C*S C^2 C*S;
                        -C*S -S^2 C*S S^2];

                ge = Ke_base;
                ge_bar = zeros(dof,dof);
                ge_bar(scatter,scatter) = ge_bar(scatter,scatter)+ge;

                l = sqrt(x'*ge_bar*x);
                dL = l-Le;
                %Create ae_bar
                ae_bar = dL/Le*ge_bar*x;
                %Create ze_bar
                ze_bar = zeros(dof,dof);
                ze = [1 0 -1 0;
                      0 1 0 -1;
                      -1 0 1 0;
                      0 -1 0 1];

                ze_bar(scatter,scatter) = ze_bar(scatter,scatter)+ze;

                %Calculate current error in terms of elastic potential:
                Ve = 1/2*(l-Le)^2;

                %Update assemblies
                Ke = Ke_base;
                K(scatter,scatter) = K(scatter,scatter) + Ke;
                A  = A + ae_bar;
                Hessian = Hessian +(Le*ge_bar + (l-Le)*ze_bar);
                V = V+Ve;
            end

            Hfree = Hessian(freenodes,freenodes);
            Afree = A(freenodes,freenodes);

            dXfree = Hfree \ (-Afree);
    %         dXfree = pinv(Hfree,-Afree);
            dxfree = dXfree(:,1);

            xfree = x(freenodes)+dxfree;
            x(freenodes) = xfree;

            iter = iter+1;  
        end

        if reverse == 1                 %If we are turning right
            xout.right(k,:) = x;
            values.right(k) = V;
        else                            %If we are turning left
            xout.left(k,:) = x;
            values.left(k) = V;
        end
        k = k+1;
        angle = phi0+input_direction*list_of_angles(k);

        if (V>err || isnan(V))      %If we are hitting infeasible domain
            infeasible_domain = 1;
            if reverse == 0
                infeasible_domain = 0;
                input_direction = -1*input_direction;
                reverse = 1;
                disp('Reversing direction')
                k = 1;
                x = x0;
                angle = phi0;
            end
        end          


    end

    values.right(all(xout.right==0,2),:) = [] ;
    values.left(all(xout.left==0,2),:) = [] ;
    xout.right(all(xout.right==0,2),:) = [] ;
    xout.left(all(xout.left==0,2),:) = [] ;

    values.left = flipud(values.left);
    xout.left = flipud(xout.left);
    values = [values.left;values.right];%Removing double appearance of x0
    xout = [xout.left;xout.right];%Removing double appearance of x0

end