function [total_reward,I,H] = test_actions(action_list)
    [I,H] = initIH;
    s = get_state(I,H);
    total_reward = get_reward (I,H);
    
    for i = 1:length(action_list)
        a = action_list(i);
        [s_new,r] = stepper(s,a);
        r
        total_reward = total_reward+r;
        s = s_new;
    end
    [I,H] = state2IH(s);
    get_reward(I,H,true)
end