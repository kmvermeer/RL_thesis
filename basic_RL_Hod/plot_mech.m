function []=plot_mech(I,H)
    hold on
    style = {'Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    scatter(H(:,1),H(:,2),'x')
    for n = 1:size(I,1)
        nodes = H(get_connections(I,n,'bar'),:);
        plot(nodes(1:2),nodes(3:4),style{:})
    end
    axis([0 10 0 10])
    grid on
end