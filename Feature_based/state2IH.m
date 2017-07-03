function [I,H] = state2IH(s)
    settings_file
    I_full = s(1:max_no_of_bars,1:max_no_of_hinges);
    H_full = s(1:2,max_no_of_hinges+1:end);
    [a,b] = find(I_full);
    final_row = max(a);
    final_col = max(b);
    I = I_full(1:final_row,1:final_col);
    [~,d] = find(H_full);
    final_row = max(d);
    H = H_full(:,1:final_row)';
end
    
