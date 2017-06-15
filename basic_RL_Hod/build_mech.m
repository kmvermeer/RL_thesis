function [I,H,M] = build_mech(H0,TDlist,linklist)
    
    H = H0;
    I = [1 1 0 0; 1 0 1 0; 0 1 0 1; 0 0 1 1];
    M = zeros(size(I,1),4);
    
    for n = 1:size(I,1)
        connections = find(I(n,:));
        h1 = H(connections(1),:);
        h2 = H(connections(2),:);
        new_link = [h1,h2];
        M(n,:) = new_link;
    end
    
    num_operators = numel(TDlist);
    
    for k = 1:num_operators
        link = linklist(k);
        if TDlist(k) == 'T'
            [I,H,M] = Ts_operator(I,H,M,link);
        else
            [I,H,M] = Ds_operator(I,H,M,link);
        end
    end
    

end