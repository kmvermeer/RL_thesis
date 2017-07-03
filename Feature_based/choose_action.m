function [Q_max,a_max,valid]= choose_action(s,w,counter,a_list)
    settings_file
    valid = true;
    [I,H] = state2IH(s);
    nM=size(I,1);
    nA = 2*max_no_of_bars;
    N0 = 150;
    epsilon = N0/(N0+counter);
     
    %Try exploration
    randy = rand();
    if ( randy<epsilon)
%         display('random choice')
        a = randi(nA);
        link = ceil(a/2);
        if link <= nM
            Q_new = get_Q(s,a,w);
            Q_max = Q_new;
            a_max = a;
        else
            valid = false;
            Q_max = 0;
            a_max = a;
        end
            
        

    else
%         display('deliberate')
        if isempty(a_list)
            a_list = [9999];            %Making sure a_list(end) is always available,
        end                               %also upon starting, when a_list is empty. 
                                        %In that case, the value 9999 is assigned, 
                                        %which will never conflict with any of the future choices.

        for a = 1:nA
            if ismember(a,a_list(end))
                Q_new = 0;
%                 display('prevented double')
            else                
                link = ceil(a/2);
                if link <= nM
                    Q_new = get_Q(s,a,w);
                else
                    Q_new = 0;
                end
            end
            Q_list(a) = Q_new;
            
        end                   
            [Q_max,a_max] = max(Q_list);
            if Q_max == 0
                a_max = randi(2*nM);
            end
    end
    
%     selection_string = strcat(operator,int2str(link));
%     display(selection_string);

end
    
    
