function [I,H] = advance_mech(I,H,operator,link)
    
    if operator == 'T'
        [I,H] = Ts_operator(I,H,link);
    else
        [I,H] = Ds_operator(I,H,link);
    end

end