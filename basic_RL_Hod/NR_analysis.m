function [x,y]=NR_analysis(q,q0,evals,nM,nH,X0,Y0,Xend,Yend)

    
    err = 1;
    errors = zeros(evals,1);
    qout = zeros(evals,length(q));
    
    for n = 1:evals
        phi2 = q0(1)+(n-1)*(1/evals)*pi;
        q(1) = phi2;
        iter = 0;
        while err>1e-3 && iter<100
            F = getF(q);
            err = norm(F);
            dFdQ = getdFdQ(q);
            dq = -dFdQ\F;
            q = q+dq';      
            iter = iter+1;
        end
        errors(n) = err;
        err = 1;
        qout(n,:) = q;
    end

    x1= X0*ones(evals,1);
    x2 = Xend*ones(evals,1);
    x = [x1 x2 qout(:,nM:nM+nH-3)]; 

    y1 = Y0*ones(evals,1);
    y2 = Yend*ones(evals,1);
    y = [y1 y2 qout(:,nM+nH-2:nM+nH-2+nH-3)];
    
end