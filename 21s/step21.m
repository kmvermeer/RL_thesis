function [s_new,r] = step21(s,a)

    player = s(1);
    dealer_open = s(2);
    dealer = dealer_open;
    
    
    %Describe HIT action
    if a == 0
        player = player+new_card(0);
        if player>21||player<1              %Case of going bust whilst hitting
           r = -1;
           term = 1;
        else
            term = 0;
            r = 0;
        end
        s_new = [player,dealer,term];
    end
    
    if a ==  1                              %Describe STICK action
        while dealer<17 && dealer>0                     %Dealer keeps hitting...
            dealer = dealer+new_card(0);  
        end
        
        if dealer>21||dealer<1||dealer<player              %Rewards based on resulting cards
            r = 1;
        elseif dealer>player
            r = -1;    
        elseif dealer == player
            r = 0;
        end
        s_new = [player,dealer_open,1] ;  
    end
end