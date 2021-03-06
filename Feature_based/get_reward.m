function [r_penalized,feasible_design] = get_reward(I,H,settings_struct,varargin)
    
    [~,~,~,~,~,~,~,negative_reward,~,~,max_no_of_bars,~,large_structure_penalty] = get_NN_settings(settings_struct);
      
    settings_file;
    Htrans = H';
    x0 = Htrans(:);
    nM = size(I,1);
    nH = size(I,2);
    L = zeros(nM,1);
    feasible_design = 1;
    addpath ../evaluation_using_FEM/
    addpath ../basic_RL_Hod/
    addpath ../Hod_operators/
   
    
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
    

    %% Determine scores and display them
    plot_trajectories = false;
    if nargin == 4
        plot_trajectories = varargin{1};
    end
    if sum(isnan(values)) == 0 && size(xout,1)>5
        
%         %straight line scoring:
        [final_score]=...
            trajectory_analysis(xout,values,I,H,x0,plot_trajectories);
        
        %Figure-eight scoring:
%     final_score = trajectory_analysis_inf(xout,values,I,H,x0,plot_trajectories);
        
        
    else
        final_score = 0;
%         disp('Infeasible design')
        feasible_design = 0;
    end
    %trying to force medium-high scores
    
    if final_score<1
        r = negative_reward;
    else
        r = final_score/100;          %Uncomment for straight lines!
%         r = final_score;            %Uncomment for figure-eights
    end
    
    %% Penalize large structures:
    penalties = linspace(large_structure_penalty ,1 ,max_no_of_bars-3);
    penalty_factor = fliplr(penalties);
    penalized_score = r * penalty_factor(nM-3);
    r_penalized = penalized_score;

end