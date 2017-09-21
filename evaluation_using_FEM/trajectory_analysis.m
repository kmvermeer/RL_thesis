function [final_score,id_max,straightness_score_list,length_straight_sections,aspect_ratio_list]= trajectory_analysis(xout,values,I,H,x0,draw_plot)
       %This function takes in all trajectories from the simulation and
       %returns an objective score, along with the underlying numbers.
       
       %% Initializing
        length_straight_sections = zeros(size(xout,2)/2,1);
        straightness_score_list = length_straight_sections;
        aspect_ratio_list = length_straight_sections;
        
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
        try
            bb_full = minbox(trajectory);
            distances = dist(bb_full);
            distances = distances(1,[2,4]);
            long_edge = max(distances);
            short_edge = min(distances);
            aspect_ratio= long_edge/short_edge;
            if sum(distances)<1e-3
                aspect_ratio = 0;
            end
            
        catch
            aspect_ratio = 0;
        end
             
      
        %Straightest section is gathered from seperate function
        [straight_section,length_straight_section] = get_straightest_section(xs,ys);
        straight_section =round(straight_section,3);
        %Building list of straight trajecotry lengths.
        length_straight_sections(i) = length_straight_section;
        no_of_unique_points = size(unique(straight_section,'rows'),1);
        x_distance = max(straight_section(:,1)) - min(straight_section(:,1));
        y_distance = max(straight_section(:,2)) - min(straight_section(:,2));
        if no_of_unique_points>3 && (x_distance>0.1 || y_distance>0.1) %If less then 4 points are valid, its scored 0.

            %Fitting minimal-surface-boxes around straight sections to determine
            %straightness
            try
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
            catch
                format long
                display(straight_section)
                display(trajectory);
                straightness_score = 0;
            end
        else
            straightness_score = 0;
        end
        %Finally, add the score to the list and plot the score in text onto
        %the figure.
        straightness_score_list(i) = straightness_score;
        aspect_ratio_list(i) = aspect_ratio;
        if draw_plot == true
            text(trajectory(1,1)+0.2,trajectory(1,2)+0.2,sprintf('Score: %2.1f',straightness_score*length_straight_section))
            for h = 1:size(H,1)
                text(H(h,1),H(h,2)+0.2,sprintf('Hinge %i',h))
            end
            for j = 1:size(I,1)
               	nodes = H(get_connections(I,j,'bar'),:);
                midx = mean(nodes(:,1));
                midy = mean(nodes(:,2));
                text(midx,midy+0.2,sprintf('Bar %i',j))
            end
                
        end
        
    end
    
    %% Consolidate scores and determine highscore
    
    length_score = length_straight_sections;
    length_score(length_score<1e-2) = 0;
    [final_score,id_max] = max(straightness_score_list.*length_score);
    if draw_plot == true
        plot(x0(2*id_max-1),x0(2*id_max),'o','MarkerSize',10,'MarkerFaceColor',[.49 1 .63])
    end
    
end


