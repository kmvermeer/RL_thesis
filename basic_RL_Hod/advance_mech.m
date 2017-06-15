function [I,H,M] = advance_mech(I,H,M,operator,link)
    
    if operator == 'T'
        [I,H,M] = Ts_operator(I,H,M,link);
    else
        [I,H,M] = Ds_operator(I,H,M,link);
    end

end