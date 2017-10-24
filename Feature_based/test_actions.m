function [total_reward,I,H,end_reward] = test_actions(action_list,varargin)
    [I,H] = initIH(10,20);
    s = get_state(I,H,10,20);
    total_reward = get_reward (I,H);
    negative_reward = -5;
    for i = 1:length(action_list)
        a = action_list(i);
        [s_new,r] = stepper(s,a,negative_reward,10,20);
        r;
        total_reward = total_reward+r;
        s = s_new;
    end
    [I,H] = state2IH(s,10,20);
    if nargin>1
        end_reward =get_reward(I,H,negative_reward,varargin{1});
    else
        end_reward =get_reward(I,H,negative_reward,true);
    end
    
    
end