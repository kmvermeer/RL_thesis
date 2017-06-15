function [Q,N,V,score,policy] = MC_analysis()
    %state = [player, dealer,termination(false-0 or true-1)]
    tic()
    nActions = 2;
    nDealers = 10;
    nPlayers = 21;

    N = zeros(nPlayers,nDealers,nActions);
    Q = zeros(nPlayers,nDealers,nActions);
    V = zeros(nPlayers,nDealers);

    count_wins = 0;
    iter = 0;
    total_draws = 0;
    total_wins = 0;
    total_losses = 0;
    iters = 50000;

    while iter<iters
        start_dealer = new_card(1);
        start_player = new_card(1);

        s0 = [start_player,start_dealer,0];
        s = s0;
        %start episode and update Q

        sa_pairs = [];
        term = s(3);
        %Play a game of 21s
        while term == 0
            player_idx = s(1);
            dealer_idx = s(2);
            action = choose_action(N,Q,s);
            action_idx = action+1;
            sa_pairs = [sa_pairs;s , action];
            N(player_idx,dealer_idx,action_idx) = N(player_idx,dealer_idx,action_idx)+1;
            [s_new,r] = step21(s,action);
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

            %Update Q
        for k=1:size(sa_pairs,1)
            player_now = sa_pairs(k,1);
            dealer_now = sa_pairs(k,2);
            action_now = sa_pairs(k,4);

            N_here = N(player_now,dealer_now,action_now+1);
            learning_rate = 1/N_here;
            error = r - Q(player_now,dealer_now,action_now+1);
            update = error*learning_rate;

            Q(player_now,dealer_now,action_now+1) = Q(player_now,dealer_now,action_now+1)+update;    
        end

        iter = iter+1;
    %     display([player_now,dealer_now,r])
    end
    score = (total_wins/iter*100);



    policy = zeros(nPlayers,nDealers);
    for i = 1:nPlayers
        for j = 1:nDealers
            [value,idx] = max(Q(i,j,:));
            V(i,j) = value;
            policy(i,j) = idx;
        end
    end
    toc()
end






















