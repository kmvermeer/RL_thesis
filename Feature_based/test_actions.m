function [total_reward,I,H,end_reward] = test_actions(action_list,settings_struct,varargin)
    [layer_settings,lr,decay_m,decay_RMS,NN_trainer_style,epochs,...
    hidden_multiplier,negative_reward,expl_factor,max_no_of_hinges,...
          max_no_of_bars,nA] = get_NN_settings(settings_struct);
      
    [I,H] = initIH(max_no_of_hinges,max_no_of_bars);
    s = get_state(I,H,max_no_of_hinges,max_no_of_bars);
    total_reward = get_reward (I,H,settings_struct);
    negative_reward = -5;
    for i = 1:length(action_list)
        a = action_list(i);
        if a == -1
            a = 0;
        end
        [s_new,r] = stepper(s,a,settings_struct);
        r
        total_reward = total_reward+r;
        s = s_new;
    end
    [I,H] = state2IH(s,max_no_of_hinges,max_no_of_bars);
    if nargin>2
        end_reward =get_reward(I,H,settings_struct,varargin{1});
    else
        end_reward =get_reward(I,H,settings_struct,true);
    end
    
    for k = 1:length(action_list)
        a = action_list(k);
        if mod(a,2) == 0
            operator = 'T';
        elseif a == -1
            operator = 'NA';
        else
            operator = 'D';
        end
        
        link = ceil(a/2);
        
        action_str = strcat(operator,num2str(link));
        if k>1
            actions = strcat(actions,', ',action_str);
        else
            actions = action_str;
        end
    end
    disp(actions)
    
    
    
end