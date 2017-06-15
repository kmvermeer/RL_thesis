function []=plotx(x,I);

   xmin = min(x)-1;
   xmax = max(x)+1;
%     figure()
    style = {'Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    hold on
    for i = 1:size(I,1)
        node = find(I(i,:));
        from = node(1);
        to = node(2);
        x1 = x(2*from-1); y1 = (x(2*from));
        x2 = x(2*to-1); y2 = (x(2*to));
        plot([x1,x2],[y1,y2],style{:})
    end
    grid on
    axis([xmin xmax xmin xmax]);
end

