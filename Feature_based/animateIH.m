function [xout] = animateIH(I,H)
    settings_file;
    Htrans = H';
    x0 = Htrans(:);
    nM = size(I,1);
    nH = size(I,2);
    L = zeros(nM,1);
    feasible_design = 1;
    addpath ../evaluation_using_FEM/
    addpath ../basic_RL_Hod/
   
    
    %% Setting free and fixed elements:
    cons_to_1 = get_connections(I,1,'hinge');
    if length(cons_to_1) == 1
        input_link = cons_to_1;
    else
        cons_to_1(cons_to_1 == 1) = [];
        input_link = min(cons_to_1);
    end
    
    input_link_hinges = get_connections(I,input_link,'bar');
    turnme_hinge = max(input_link_hinges);
    fixme = [1,2];
    fixed = [fixme,turnme_hinge];
    nodes = 1:1:2*nH;
    fixnodes = sort([2*fixed-1 2*fixed]);
    freenodes = nodes;
    freenodes(fixnodes) = [];

    %% Determining initial lenghts and angle phi0
    for i = 1:nM
        node = get_connections(I,i,'bar');
        from = node(1);
        to = node(2);
        x1 = x0(2*from-1); y1 = (x0(2*from));
        x2 = x0(2*to-1); y2 = (x0(2*to));
        L(i) = sqrt((x2-x1)^2+(y2-y1)^2);
        if i == input_link
            phi0 = atan2(y2-y1,x2-x1);
        end
    end
    
    
    %% Performing FEA 
    [xout,values]=FEA(I,x0,phi0,L,input_link,freenodes,turnme_hinge);
    no_of_frames = 60;
    
    X = xout;
    nM = size(I,1);
    fig = figure('Visible','on');
    style = {'Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    style_off = {'r-','Marker','o','MarkerSize',7,'MarkerFaceColor', ...
        'black','linewidth',2.5};
    minx = min(min(X(:,1:2:end)));   %
    miny = min(min(X(:,2:2:end)));
    maxx = max(max(X(:,1:2:end))); 
    maxy = max(max(X(:,2:2:end)));
    
    
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

        axis([-1 1 -1 1]+[minx maxx miny maxy]);
        hold off
        screenshots(i) = getframe();
        clf
    end

end