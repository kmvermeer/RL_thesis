function []=plot_mech(I,H,M)
    hold on
    style = {'Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    scatter(H(:,1),H(:,2),'x')
    for n = 1:size(I,1)
        plot([M(n,1),M(n,3)],[M(n,2),M(n,4)],style{:})
    end
    grid on
    axis equal
end