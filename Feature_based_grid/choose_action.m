function [Q_max,a_max]= choose_action(s,w,counter,a_list)
    settings_file
    if isempty(a_list)
        a_list = 1000;
    end
    [I,H] = state2IH(s);
    nM=size(I,1);
    
    N0 = 5;
    Q_list = [];
    epsilon = N0/(N0+counter);
     
    randy = rand();
    if ( randy<epsilon)
        display('random choice')
        a = randi(nM*2);
        link = ceil(a/2);
            if mod(a,2) == 0
                operator = 'T';
            else
                operator = 'D';
            end
        [I_new,H_new] = advance_mech_gridworld(I,H,operator,link,gridxy);
        s_new= get_state(I_new,H_new);
        Q_new = get_Q(s_new,w);
        Q_max = Q_new;
        a_max = a;
        

    else
        display('deliberate')
        for a = 1:2*nM
            if ismember(a,a_list(end))
                Q_new = 0;
                display('prevented double')
            else                
                link = ceil(a/2);
                if mod(a,2) == 0
                    operator = 'T';
                else
                    operator = 'D';
                end
                [I_new,H_new] = advance_mech_gridworld(I,H,operator,link,gridxy);
                s_new= get_state(I_new,H_new);
                Q_new = get_Q(s_new,w);
            end
            Q_list(a) = Q_new;
            
        end                   
            [Q_max,a_max] = max(Q_list);
            if Q_max == 0
                a_max = randi(2*nM);
            end
    end
    selection_string = strcat(operator,int2str(link));
    display(selection_string);

end
    
    
