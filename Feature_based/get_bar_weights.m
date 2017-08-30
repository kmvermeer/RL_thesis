function [barplot, barplot_text] = get_bar_weights(w,nF,counter)
    figure()

    barplot = bar(1:1:nF,w);
%     barplot_text = text(20,1.7,int2str(counter),'FontName',e'Cambria','FontSize',10);
        
    dim = [.15 .7 .7 .15];
    
    
    str = strcat('Epochs: ',int2str(counter));
    barplot_text = annotation('textbox',dim,'String',str,'FitBoxToText','on','BackgroundColor','black','FaceAlpha',.2);
    
    
    axis([0,nF,-1,2])
    grid on
    title('Feature weights \theta')
    xlabel('Feature')
    ylabel('Weight')
end

