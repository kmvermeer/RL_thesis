function [I_new,H_new,feasible_design] = Ts_operator(I,H,link)
    feasible_design =1;
    %Determine new hinge location and add to H
    base_link_hinges = find(I(link,:));
    base_vec = diff(H(base_link_hinges,:))';
    nM = size (I,1);
    nH = size(I,2);
    new_hing_col = zeros(nM,1);

    %Formulas to find COM x and y for a mass
    get_mean_xy = @(mass) mean(H(get_connections(I,mass,'bar'),:),1);

    xy_com = get_mean_xy(link);
    x_com = xy_com(1);
    y_com = xy_com(2);
    L = norm(base_vec);
    if L == 0
        I_new = I;
        H_new = H;
        return   
    end
    unit_link = base_vec/L;
    new_unit_link = null(unit_link');
    

    neighbour_links = find(I(:,base_link_hinges));
    neighbour_links = mod(neighbour_links,nM);
    neighbour_links(neighbour_links == 0) = nM;
    neighbour_links(neighbour_links == link) = [];
    COMs = [];

    for q = 1:length(neighbour_links)
        COM = get_mean_xy(neighbour_links(q));
        COMs = [COMs;COM];
    end
    COM_neighbours = mean(COMs,1);
    x_neighbours = COM_neighbours(1);
    y_neighbours = COM_neighbours(2);

    %If angle from base link's COM is close to the unit vector perp to the
    %link, we choose opposing side of the base link for the new point.
    com2neighbours = [x_neighbours-x_com;y_neighbours-y_com];
    get_angle = @(u,v) dot(u,v)/(norm(u)*norm(v));
    try
        angle = acos(get_angle(com2neighbours,new_unit_link));
    catch
        keyboard
    end
    
    if angle<(pi/2)
        direction = -1;
    else
        direction = 1;
    end
    newpos = [x_com;y_com]+direction*L*new_unit_link;
    H_new = vertcat(H,newpos');

    %Determine closes hinge
    cross_list = [0 0 0];
    drops = [min(base_link_hinges),max(base_link_hinges),size(H_new,1)];
    H_new_base = H_new;
    H_new_base(drops,:) = [];

    while numel(cross_list)>0
        H_for_closest = H_new;
        H_for_closest(drops,:) = [];

        %FIX: if no non-crosser can be found, just select closest.
        if size(H_for_closest,1)==0
            closest_hinge = dsearchn(H_new_base,newpos');
            break
        end

        closest_hinge = dsearchn(H_for_closest,newpos');
        hing_no_in_closestH = ismember(H_new,H_for_closest(closest_hinge,:),'rows');
        closest_hinge = find(hing_no_in_closestH,1);

        %Check for crosses
        new_link = [H_new(closest_hinge,:),H_new(end,:)];
        try
            cross_list = detect_crossing(I,H,link,new_link);
        catch
            keyboard
        end
        %If corssing occurs, delete currently selected hinge from search space
        if numel(cross_list)>0
            drops = [drops,closest_hinge];
        end 
    end


    %Create new rows for links in I
    new_bar1_base_row = zeros(1,nH);
    new_bar1_base_row(base_link_hinges(1))=1;
    new_bar1_row = [new_bar1_base_row,1];

    new_bar2_base_row = zeros(1,nH);
    new_bar2_base_row(base_link_hinges(2))=1;
    new_bar2_row = [new_bar2_base_row,1];

    replacement_link_base_row = zeros(1,nH);
    replacement_link_base_row(closest_hinge)=1;
    replacement_link = [replacement_link_base_row,1];

    %Construct I
    I_interim = [I,new_hing_col];
    I_interim(link,:) = replacement_link;
    I_new = vertcat(I_interim,new_bar1_row,new_bar2_row);
    
    %Test for duplicates in H
    [C,A,~] = unique(H_new, 'rows', 'first');
    hasDuplicates = size(C,1) < size(H_new,1);
    if hasDuplicates
        ixDupRows = setdiff(1:size(H_new,1), A);
        dupRowValues = H_new(ixDupRows,:);
%             display('double hinges whilst performing Ds on link');
%             display(dupRowValues);
        H_new = H;
        I_new = I;
        feasible_design = 0;
    end
        
        
end

