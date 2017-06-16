function [final_score,id_max,straightness_score_list,length_straight_sections]= trajectory_analysis(xout,values,I,x0,draw_plot)
       %This function takes in all trajectories from the simulation and
       %returns an objective score, along with the underlying numbers.
       
       %% Initializing
        length_straight_sections = zeros(size(xout,2)/2,1);
        straightness_score_list = length_straight_sections;
        if draw_plot == true
            figure();
        end
        
        %Tossing out infeasible domain (if aparent)
        x_feasible = xout(values<1e-3,:);       %Removing part of trajectory with infeasible values

        
    %% Looping over every seperate trajectory (one for each hinge-point)       
    for i = 3:(size(x_feasible,2)/2)
        xs = x_feasible(:,2*i -1);
        ys = x_feasible(:,2*i);
        trajectory = [xs,ys];
      
        %Straightest section is gathered from seperate function
        [straight_section,length_straight_section] = get_straightest_section(xs,ys);
        
        %Building list of straight trajecotry lengths.
        length_straight_sections(i) = length_straight_section;
        no_of_unique_points = size(unique(straight_section,'rows'),1);
        if no_of_unique_points>3 %If less then 4 points are valid, its scored 0.

            %Fitting minimal-surface-boxes around straight sections to determine
            %straightness
            bb = minbox(straight_section);
            distances = dist(bb);
            distances = distances(1,[2,4]);
            long_edge = max(distances);
            short_edge = min(distances);
            
            %Determine straightness score
            straightness_score = long_edge/short_edge;
            
            %plotting trajectories (one by one and holding on)
            if draw_plot == true
                plot(trajectory(:,1),trajectory(:,2),'--')
                hold on
                plot(straight_section(:,1),straight_section(:,2),'*')
                plotx(x0,I)
                bbx = [bb(1,:) bb(1,1)];
                bby = [bb(2,:) bb(2,1)];
                plot(bbx,bby)
                axis equal
            end
            
        %Set score to 0 if there is not enough 'straight' points available
        else
            straightness_score = 0;
        end
        %Finally, add the score to the list and plot the score in text onto
        %the figure.
        straightness_score_list(i) = straightness_score;
        text(trajectory(1,1)+0.2,trajectory(1,2)+0.2,sprintf('Score equals: %2.1f',straightness_score*length_straight_section))
    end
    
    %% Consolidate scores and determine highscore
    
    length_score = length_straight_sections;
    length_score(length_score<1e-2) = 0;
    [final_score,id_max] = max(straightness_score_list.*length_score);
    if draw_plot == true
        plot(x0(2*id_max-1),x0(2*id_max),'o','MarkerSize',10,'MarkerFaceColor',[.49 1 .63])
    end
    
end


