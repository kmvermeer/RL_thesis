function [features] = get_features(I,H)

    settings_file;
    Htrans = H';
    x0 = Htrans(:);
    nM = size(I,1);
    nH = size(I,2);
    L = zeros(nM,1);

    addpath /Users/kazv/Documents/TU/Thesis/MATLAB/evaluation_using_FEM/
    addpath /Users/kazv/Documents/TU/Thesis/MATLAB/basic_RL_Hod/
    addpath /Users/kazv/Documents/TU/Thesis/MATLAB/Hod_operators/

    nF = max_no_of_hinges-3;
    features = zeros(nF,1);
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
%     display(I)
%     display(x0)
%     display(L)
%     if length(x0) ~= 2*size(I,2)
%         disp('weird shit')
%     end
    [xout,values]=FEA(I,x0,phi0,L,input_link,freenodes,turnme_hinge);

    %% Determine scores and display them
    if sum(isnan(values)) == 0 && size(xout,1)>5
        [final_score,id_max,straightness_score_list,length_straight_sections,aspect_ratio_list]=... 
            trajectory_analysis(xout,values,I,x0,false);
%         scores = straightness_score_list.*length_straight_sections;
        if length(aspect_ratio_list)<max_no_of_hinges
                features(1:(length(aspect_ratio_list)-2)) = sqrt(aspect_ratio_list(3:end));
        else
            features(1:nF) = sqrt(aspect_ratio_list(3:nF+2));
        end
        if sum(features) == 0
            keyboard
        end
        if isnan(features(1))
            keyboard
        end
    end
end
