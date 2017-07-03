function [Q,f_full] = get_Q(s,w)
    settings_file;
    [I,H] = state2IH(s);
    
    
    f_full = zeros(1,nF);
    f_s = get_features(I,H);
    
    f_full(1:length(f_s)) = f_s;
    try
        Q = f_full*w(1:end)';
    catch

        keyboard
    end
end