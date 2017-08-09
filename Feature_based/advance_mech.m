function [I,H,feasible_design] = advance_mech(I,H,operator,link)
    
    if operator == 'T'
        [I,H,feasible_design] = Ts_operator(I,H,link);
    else
        [I,H,feasible_design] = Ds_operator(I,H,link);
    end

end