function [Q,F] = get_Q(s,a,w)
    settings_file;
   
    [F] = get_features(s,a);
        
    Q = F*w(1:end)';
end