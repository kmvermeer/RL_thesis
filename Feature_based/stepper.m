function [s_new,r,feasible_design] = stepper(s,a,negative_reward,max_no_of_hinges,max_no_of_bars)
    
    [I,H] = state2IH(s,max_no_of_hinges,max_no_of_bars);
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
        s_new = get_state(I,H,max_no_of_hinges,max_no_of_bars);
        if feasible_design == 1 
            [r,feasible_design] = get_reward(I,H,negative_reward);
        else
            r = negative_reward;
        end
    end
end



