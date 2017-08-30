function [F,nF] = get_features(s,a)
    settings_file
    [I_orig,H_orig] = state2IH(s);
    bias_feature = 1;

    %% Things to notice about the current action:
    
    %Boolean for operator type
    if mod(a,2) == 0
        isitT = 1;
        isitD = 0;
        operator = 'T';
    else
        isitT = 0;
        isitD = 1;
        operator = 'D';
    end
    
    %Boolean list of selected bar to act on:
    selected_bar = zeros(1,max_no_of_bars);
    link = ceil(a/2);
    selected_bar(link) = 1;
    
    %% Things to notice about the current structure:
    nM_current = size(I_orig,1);
    %Booleon whether selected bar exists
    bar_exist = 1;
    if link>nM_current
        bar_exist = 0;
    end
    
    %number of connected links to current link
    if link>nM_current
        no_of_cons_to_link = 0;
    else
        connections = get_connections(I_orig,link,'bar');
        no_of_cons_to_link = length(connections)/4; %division to semi-normalize
    end
    
    
    %% Resulting structure:
    if bar_exist == 1
        [I,H] = advance_mech(I_orig,H_orig,operator,link);
    else
        I = I_orig;
        H = H_orig;
    end
    
    nM = size(I,1);
    nM_norm = nM/max_no_of_bars;
    nH = size(I,2);
    nH_norm = nH/max_no_of_hinges;
    
    
    %Feature vector is long list of features:
    settings_file
    hinge_active = zeros(1,max_no_of_hinges);
    bar_active = zeros(1,max_no_of_bars);
    hinge_active(1:nH) = 1;
    bar_active(1:nM) = 1;

    %Get lengths w.r.t base link
    rel_L = zeros(1,max_no_of_bars);
    for i = 1:nM
        node = get_connections(I,i,'bar');
        from = node(1);
        to = node(2);
        x1 = H(from); y1 = H(from+nH);
        x2 = H(to); y2 = H(to+nH);
        rel_L(i) = sqrt((x2-x1)^2+(y2-y1)^2);
    end
    rel_L = 1/(rel_L(1))*rel_L;


    %Get relative angles per hinge
    rel_angle = zeros(1,max_no_of_bars);
    for k = 1:nH
        bars = get_connections(I,k,'hinge');
        nbars = length(bars);
        vectors = [];
        for p = 1:nbars
            bar = bars(p);
            cons = get_connections(I,bar,'bar');
            other_node = cons(cons~=k);
            cons_sorted = [k,other_node];
            coordinates = H(cons_sorted,:);
            vector = diff(coordinates)';
            vectors = [vectors vector];
        end
        possibilities = nchoosek(1:nbars,2);
        alphas = zeros(size(possibilities,1),1);
        for j = 1:size(possibilities,1)
            combination = possibilities(j,:);
            vec1 = vectors(:,combination(1));
            vec2 = vectors(:,combination(2));
            vec1 = vec1/norm(vec1);
            vec2 = vec2/norm(vec2);
            alphas(j) = acos(dot(vec1,vec2));
        end
        rel_angle(k) = max(abs(alphas))/pi;      
    end
    
    %Determine which bars are connected to base
    con2base = zeros(1,max_no_of_bars);
    ground1 = get_connections(I,1,'hinge');
    ground2 = get_connections(I,2,'hinge');
    grounded_bars = unique([ground1;ground2]);
    con2base(grounded_bars) = 1;
    
    %% Getting graph-type features from seperate function:
    
    graph_features = get_graph_features(I,max_no_of_hinges,max_no_of_bars);
    
    %% Assembling F(s) into vector
    sub_F = [nM_norm,nH_norm,hinge_active,bar_active,rel_L,...
            rel_angle,con2base,isitT,isitD,selected_bar,...
            bar_exist,no_of_cons_to_link,graph_features];

%     sub_F = [nM_norm,isitT,isitD,selected_bar,bar_exist,no_of_cons_to_link];
    no_sub_F = size(sub_F,2);
    

    %Putting F(s) into feature vector F(s,a) and adding bias feature
%     F = zeros(1,no_sub_F*nA+1);
%     F(1) = bias_feature;
%     idx_start = (a-1)*no_sub_F+2;         %Uncomment for dimensionality..
%                                            trick
%     idx_end = idx_start+no_sub_F-1;
%     F(idx_start:idx_end) = sub_F;

    F = [bias_feature,sub_F];         %Turn on to go back to small F (no..
%                                      spreading per action).
    nF = size(F,2);
    end
