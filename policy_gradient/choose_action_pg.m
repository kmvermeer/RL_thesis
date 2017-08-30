function [a,score_fun] = choose_action_pg(s,w_a)
    settings_file
    Fs = [];
    
    for action = 1:nA
        F = get_features(s,action);
        Fs = [Fs ; F];
    end
    
    exponents = Fs*w_a';
    prob_total = exp(exponents);
    prob_norm = prob_total./sum(prob_total);
    %Determine cumulative distribution function (CDF)
    CDF = cumsum(prob_norm);
    
    %Throw dice
    r = rand(1);
    
    %Find according action (equals according index)
    a = find(CDF>r,1); 
    
    %Establish score function delta log pi
    try 
        score_fun = get_features(s,a)- mean(Fs);
    catch
        keyboard()
    end
end