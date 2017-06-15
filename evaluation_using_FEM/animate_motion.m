function [screenshots] = animate_motion(I,X,nM,values)
     
    no_of_frames = 20;
    
    fig = figure('Visible','on');
    style = {'Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    style_off = {'r-','Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    minx = min(X(:));
    maxx =max(X(:));

    stepsize = floor(size(X,1)/no_of_frames);
    if stepsize == 0
        stepsize = 1
    end
    
    for i = 1:stepsize:size(X,1)
        grid on
        hold on
        for k=1:nM
            hinges = find(I(k,:));
            fr = hinges(1);
            to = hinges(2);
            x1 = X(i,2*fr-1) ; y1 = X(i,2*fr);
            x2 = X(i,2*to-1) ; y2 = X(i,2*to);
            if values(i)>1e-2
                plot([x1,x2],[y1,y2],style_off{:});
            else
                plot([x1,x2],[y1,y2],style{:});
            end
        end

        axis(1.1*[minx maxx minx maxx]);
        hold off
        screenshots(i) = getframe();
        clf
    end

end