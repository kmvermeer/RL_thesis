function [I,H] = advance_mech_gridworld(I,H,operator,link,gridxy)
    
    if operator == 'T'
        [I,H] = Ts_operator_grid(I,H,link,gridxy);
    else
        [I,H] = Ds_operator_grid(I,H,link,gridxy);
    end

end