function [straight_section,length_straigth_section] = get_straightest_section(x,y)
    %This function takes in the x and y vectors of a trajectory and returns
    %the straightest section.
    
    %Room for improvement: selection of 'straightest' part is now based on
    %a ratio. This means the number of points identified as 'straight' is
    %dependent on the total number of points in the trajectery, whereas
    %there is no rationale for this.
    
    %% Important settings:
    outlier_threshold = 0.2;
    straight_section_fraction= 0.25;
    
    %% Initial calculations and filtering
    %Determine the direction of the path between each point in the
    %trajectory. Deviations in the direction are normalized by path length
    %and the result used as a measure for curvature.
    dx = diff(x);
    dy = diff(y);
    angles = atan2(dy,dx);  
    dangles = [0;diff(angles)];
    
    %Filtering outliers that are certainly not straight, by assuming that
    %angle deviations over 0.2 are huge.
    abs_dangles = abs(dangles);
    while (max(abs_dangles)>outlier_threshold)
        M = mean(abs_dangles);
        sd = std(abs_dangles);
        selection = abs_dangles>(M+2*sd);
        if sum(selection) == 0
            break
        end
        dangles(selection) = NaN;
        abs_dangles = abs(dangles);
    end
    
    %Normalizing dangles
    stepsize = sqrt(dx.^2+dy.^2);
    norm_dangles = dangles./stepsize;
    
    %Filtering out very high normalized angles (resulting from tiny
    %stepsizes) and infinite values.
    conditionA = abs(norm_dangles)>20*mean(abs(norm_dangles));
    conditionB = (abs(norm_dangles)>999);
    while sum(conditionA)~=0 || sum(conditionB)~=0
        AorB = or(conditionA,conditionB);
        norm_dangles(AorB)=NaN;
        conditionA = abs(norm_dangles)>20*mean(abs(norm_dangles));
        conditionB = (abs(norm_dangles)>50);
    end
    
    %% Determining what's straight
    %Determine number of elements allowed in the straight_selection (25%)
    [~,sorted_idx] = sort(abs(norm_dangles));
    idx_max = floor(length(dangles)*straight_section_fraction);
    
    
    %Select straight idx accordingly
    selected_idx = sorted_idx(1:idx_max);
    all_indices = 1:length(dangles);
    selected_index_logicals = [0 ismembc(all_indices,sort(selected_idx)) 0];
    starters = find(diff(selected_index_logicals) == 1);
    enders = find(diff(selected_index_logicals) == -1);
    groups_of_straights = enders-starters;
    [max_len,idx] = max(groups_of_straights);
    
    from = starters(idx);
    to = from+max_len;
    
    straight_section = [x(from:to),y(from:to)];
    if isempty(straight_section) == 1
        length_straigth_section = 0;
    else
        length_straigth_section = norm(diff([straight_section(1,:);straight_section(end,:)]));
    end
end