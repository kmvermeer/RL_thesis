function [final_score]= trajectory_analysis(x,y,I,H,M)
    cross2d = @(a,b) a(1)*b(2) - a(2)*b(1);

    score_list=[];

    for i = 3:size(x,2)

        trajectory = [x(:,i),y(:,i)];
        steps = diff(trajectory);
        real_steps = steps(abs(steps)>0.001);
        mean_step = mean(real_steps);
        outliers = real_steps(abs(real_steps)>10*abs(mean_step));
        if not(isempty(outliers))
            idx = find(steps(:,1) == outliers(1));
            if isempty(idx)
                idx = find(steps(:,2) == outliers(1));
            end
            trajectory = trajectory(1:idx,:);
        end
        
        plot(trajectory(:,1),trajectory(:,2))
        hold on
        starting = trajectory(1,:);
        ending = trajectory (end,:);
        L = abs(norm(ending-starting));
        direction = (ending - starting) /(norm(ending-starting));
        normal = null(direction);
        r = direction;
        s = normal;
        q = starting;
        us = [];

        for i=1:length(trajectory)
            p = trajectory(i,:);
            u = cross2d((p-q),r)/cross2d(s,r);        
            us = [us;abs(u)];
            plot([p(1),p(1)-u*s(1)],[p(2),p(2)-u*s(2)],'-*')

        end
        score = L/max(us);
        score_list = [score_list;score];
        plot([starting(1),ending(1)],[starting(2),ending(2)],'--');

    end
    final_score = max(score_list);
    plot_mech(I,H,M)
    axis equal
end

