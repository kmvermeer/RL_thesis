function [s_new,r] = stepper(s,a)
    
    settings_file
    [I,H] = state2IH(s);
    link = ceil(a/2);
    if mod(a,2) == 0
        operator = 'T';
    else
        operator = 'D';
    end
    
    nM = size(I,1);
    if a>2*nM
        r = 0;
        s_new = s;
    else
        [I,H] = advance_mech_gridworld(I,H,operator,link,gridxy);
        I
        H
        s_new = get_state(I,H,gridxy,max_no_of_hinges);
        r = get_reward(I,H);
    end
end



