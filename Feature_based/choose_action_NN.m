function [Q_max,a_max,random_bool]= choose_action_NN(s,weights,a_list,counter,layer_settings,expl_factor)
    settings_file
    valid = true;
    [I,H] = state2IH(s);
    nM=size(I,1);
    nA = 2*max_no_of_bars;
    N0 = epochs/expl_factor;
    if counter == 'deterministic'
        epsilon = 0;
    else
        epsilon = N0/(N0+counter);
    end
     
    %Try exploration
    randy = rand();
    if ( randy<epsilon)
%         display('random choice')
        random_bool = 1;
        a = randi(nA);
        link = ceil(a/2);
        if link <= nM
            Q_new = get_Q_NN(s,a,weights,layer_settings);
            Q_max = Q_new;
            a_max = a;
        else
            valid = false;
            Q_max = 0;
            a_max = a;
        end
            
        

    else
        random_bool = 0;
%         display('deliberate')
        if isempty(a_list)
            a_list = [9999];            %Making sure a_list(end) is always available,
        end                               %also upon starting, when a_list is empty. 
                                        %In that case, the value 9999 is assigned, 
                                        %which will never conflict with any of the future choices.

        parfor a = 1:nA
            if ismember(a,a_list(end))
                Q_new = 0;
                display('prevented double')
            else                
%                 link = ceil(a/2);
%                 if link <= nM
                Q_new = get_Q_NN(s,a,weights,layer_settings);          
%                 else
%                     Q_new = 0;
%                 end
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
    
    
