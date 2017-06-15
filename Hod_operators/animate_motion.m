function [] =animate_motion(I,x,y,nM,evals)
    
    fig = figure('Visible','on');
    style = {'Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    min_max_x = [min(x(:)) max(x(:))];
    min_max_y = [min(y(:)) max(y(:))];

    for i = 1:evals
        grid on
        hold on
        for k=1:nM
            hinges = find(I(k,:));
            fr = hinges(1);
            to = hinges(2);
            plot([x(i,fr),x(i,to)],[y(i,fr),y(i,to)],style{:});
        end

        axis(1.1*[min_max_x min_max_y]);
        hold off
        screenshots(i) = getframe();
        clf
    end

end

