%3    12    16
a_list = [3 12 16];

for i = 1:3
    a = a_list(i);
    link = ceil(a/2);
    if mod(a,2) == 0
        operator = 'T';
    else
        operator = 'D';
    end
    [I,H] = advance_mech_gridworld(I,H,operator,link,gridxy);
    a
    r = get_reward(I,H)
    
   
   
end