function [str] = I2str(I)
    nM = size(I,1);
    str = zeros(nM,1);
    for M = 1:nM
        node = sort(get_connections(I,M,'bar'));
        
        %Following eq 3.13 in Kuppens
        
        %Assigning v1 and v2 such that v1>v2
        v1 = node(2);
        v2 = node(1);
        
        %Determining (v1-1) over (2). If v1 = 2, the combination is
        %manually set to 0, resuling in incidence no 1.
        if v1~=2
            combination = nchoosek(v1-1,2);
        else
            combination = 0;
        end
        inc = combination +v2;
        str(M) = inc;
    end
end
