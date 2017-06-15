%     function [Q,N,V,score] = TD(lambda)
clear all
clc
%state = [player, dealer,termination(false-0 or true-1)]
[MC.Q,MC.N,MC.V,MC.score] = MC();
nActions = 2;
nDealers = 10;
nPlayers = 21;

N = zeros(nPlayers,nDealers,nActions);
Q = zeros(nPlayers,nDealers,nActions);
V = zeros(nPlayers,nDealers);

lambda = 0.3;

count_wins = 0;
iter = 0;
total_draws = 0;
total_wins = 0;
total_losses = 0;
iters = 10000;

MSE_vec = [];

while iter<iters
    E = zeros(nPlayers,nDealers,nActions);
    start_dealer = new_card(1);
    start_player = new_card(1);

    s0 = [start_player,start_dealer,0];
    s = s0;
    %start episode and update Q
    term = s(3);
    action = choose_action(N,Q,s);
    action_idx_new = action+1;
    %Play a game of 21s
    while term == 0
        player_idx = s(1);
        dealer_idx = s(2);
        action_idx = action+1;
%         sa_pairs = [sa_pairs;s , action];
        Ns = N(player_idx,dealer_idx,action_idx);
        N(player_idx,dealer_idx,action_idx) = Ns+1;
        [s_new,r] = step21(s,action);
        Qstep1 = Q(player_idx,dealer_idx,action_idx);
               
        if s_new(3) == 0
            player_idx_new = s_new(1);
            dealer_idx_new = s_new(2);
            action_idx_new = choose_action(N,Q,s_new)+1;
    
            Qstep2 = Q(player_idx_new,dealer_idx_new,action_idx_new);
            
            delta = r+Qstep2-Qstep1;
        else
            delta = r-Qstep1;
        end
        
        E(player_idx,dealer_idx,action_idx) = E(player_idx,dealer_idx,action_idx)+1;
        alpha = 1/(Ns+1);
        
        Q = Q+alpha*delta*E;
        E = lambda*E;
        action = action_idx_new-1;

        s = s_new;
        term = s(3);
    end
    if r==1
        total_wins = total_wins+1;
    elseif r==0
        total_draws = total_draws+1;
    elseif r == -1
        total_losses = total_losses+1;
    end
    
    error = Q-MC.Q;
    error_squared = error.^2;
    MSE = sum(error_squared(:))/numel(N);
    MSE_vec = [MSE_vec;MSE];
    iter = iter+1;
end
display(total_wins/iter*100)



for i = 1:nPlayers
    for j = 1:nDealers
        V(i,j) = max(Q(i,j,:));
    end
end






