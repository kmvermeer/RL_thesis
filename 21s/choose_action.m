function action= get_action(N,Q,state)
    
    N0 = 100;

    player_idx = state(1);
    dealer_idx = state(2);
    
    Ns = sum(N(player_idx,dealer_idx,:));
    
    epsilon = N0/(N0+Ns);
    
    randy = rand();
    if randy<epsilon
        action = randi(2)-1;
    else
        [val,idx] = max(Q(player_idx,dealer_idx,:));
        action = idx-1;            
    end
end
    
    
