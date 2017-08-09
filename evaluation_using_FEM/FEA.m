function [xout,values]=FEA(I,x0,phi0,L,input_link,freenodes,turnme_hinge)
    %% Initializing matrices and values for FEA
    err = 1e-4;
    max_iter = 100;
    settings_file
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
    
    list_of_angles = linspace(0,2*pi,evals);
    k = 1;
    infeasible_domain = 0;
    
    connected_to_input_link = get_connections(I,input_link,'bar');
    base_hinge = connected_to_input_link(connected_to_input_link~=turnme_hinge);
    
    nodes = zeros(nM,2);
    for i =1:nM
        nodes(i,:) = get_connections(I,i,'bar');
    end
    
    
    while k<evals && not(infeasible_domain == 1 && reverse == 1)
    %     dphi = 0;

        x(2*turnme_hinge-1) = L(input_link)*cos(angle)+x0(2*base_hinge-1);
        x(2*turnme_hinge) = L(input_link)*sin(angle)+x0(2*base_hinge);
        V = 1;
        iter = 0;
        LR = lr_FEA; %Setting learning rate to default value from settings file
        while V>err && iter<max_iter
            V_old = V;
            K = zeros(dof,dof);
            A = K;
            Hessian = K;
            V = 0;
            for i = 1:nM
                node = nodes(i,:);
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
            
            if V>V_old
                LR = LR/2;
                iter = iter+1;
            elseif V>err && not(isnan(V))
                Hfree = Hessian(freenodes,freenodes);
                Afree = A(freenodes,freenodes);
                dXfree = Hfree \ (-Afree);
                dxfree = dXfree(:,1);

                xfree = x(freenodes)+LR*dxfree;
                x(freenodes) = xfree;

                iter = iter+1;
            end           
        end
        
        if reverse == 1 && V<err                %If we are turning right
            xout.right(k,:) = x;
            values.right(k) = V;
        elseif reverse ==0 && V<err             %If we are turning left
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
%                 disp('Reversing direction')
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
    values = [values.left;values.right(2:end,:)];%Removing double appearance of x0
    xout = [xout.left;xout.right(2:end,:)];%Removing double appearance of x0
    
end