function [total_reward,I,H,end_reward] = test_actions(action_list,settings_struct,varargin)
    [layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,...
    hidden_multiplier,negative_reward,expl_factor,max_no_of_hinges,...
          max_no_of_bars,nA] = get_NN_settings(settings_struct);
      
    [I,H] = initIH(max_no_of_hinges,max_no_of_bars);
    s = get_state(I,H,max_no_of_hinges,max_no_of_bars);
    total_reward = get_reward (I,H);
    negative_reward = -5;
    for i = 1:length(action_list)
        a = action_list(i);
        [s_new,r] = stepper(s,a,negative_reward,max_no_of_hinges,max_no_of_bars);
        fprintf('New reward: %2.1f \n',r)
        total_reward = total_reward+r;
        s = s_new;
    end
    [I,H] = state2IH(s,max_no_of_hinges,max_no_of_bars);
    if nargin>2
        end_reward =get_reward(I,H,negative_reward,varargin{1});
    else
        end_reward =get_reward(I,H,negative_reward,true);
    end
    
    
end