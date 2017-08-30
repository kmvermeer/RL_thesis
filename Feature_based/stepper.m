function [s_new,r,feasible_design] = stepper(s,a)
    
    settings_file
    [I,H] = state2IH(s);
    link = ceil(a/2);
    if mod(a,2) == 0
        operator = 'T';
    else
        operator = 'D';
    end
    
    nM = size(I,1);
    if link>nM
        r = negative_reward;
        s_new = s;
        feasible_design = 1;
    else
        [I,H,feasible_design] = advance_mech(I,H,operator,link);
        s_new = get_state(I,H);
        if feasible_design == 1 
            [r,feasible_design] = get_reward(I,H);
        else
            r = negative_reward;
        end
    end
end



