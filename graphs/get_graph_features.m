
function graph_feature_vector = get_graph_features(I,H,max_no_of_hinges,max_no_of_bars,shortest_path)
    nM = size(I,1);
    nH = size(I,2);
    from = [];
    to = [];
    weights = [];

    %% Creating placeholder feature list:
    init_ft_hinge = zeros(1,max_no_of_hinges);
    init_ft_bar = zeros(1,max_no_of_bars);
    
    ft_betweenness = init_ft_hinge;
    ft_degrees = init_ft_hinge;
    ft_closeness = init_ft_hinge;
    ft_pagerank = init_ft_hinge;
    ft_eigenvector = init_ft_hinge;
    ft_graph_density = 0;
    ft_mean_graph_distance = 0;
    ft_graph_efficiency = 0;
    ft_laplacian_eigenvalues = init_ft_hinge;
    ft_no_of_spanning_trees = 0;
    ft_part_of_min_span_tree = init_ft_bar;
    ft_spectral_gap = 0;
    ft_Fiedler_value = 0;
    ft_eccentricity = init_ft_hinge;
    ft_radius = 0;
    ft_diameter = 0;
    ft_part_of_center = init_ft_hinge;
    ft_part_of_periphery = init_ft_hinge;
    ft_no_of_cycles = 0;
    ft_part_of_longest = init_ft_bar;
    ft_part_of_shortest = init_ft_bar;
    ft_longest_circle_length = 0;
    ft_shortest_circle_length = 0;
    ft_cluster_coef = init_ft_hinge;
    if shortest_path == true; ft_SPs = zeros(1,max_no_of_hinges * (max_no_of_hinges -1) / 2);end
    
    graph_feature_vector =[ft_betweenness, ft_degrees, ft_closeness,...
        ft_pagerank, ft_eigenvector, ft_graph_density,...
        ft_mean_graph_distance, ft_graph_efficiency,...
        ft_laplacian_eigenvalues, ft_no_of_spanning_trees,...
        ft_part_of_min_span_tree, ft_spectral_gap, ft_Fiedler_value,...
        ft_eccentricity, ft_radius, ft_diameter, ft_part_of_center,...
        ft_part_of_periphery, ft_no_of_cycles, ft_part_of_longest, ...
        ft_part_of_shortest, ft_longest_circle_length,...
        ft_shortest_circle_length, ft_cluster_coef];
        
    
    if length(unique(I,'rows')) ~= length(I)
        return   
    end
    
    %% Create graph objects G and E:
    
    for k = 1:nM
        barI = I(k,:);
        nodes = find(barI);
        f = nodes(1);
        t = nodes(2);
        from = [from f];
        to =[to t];
        w = norm(H(nodes(1),:) - H(nodes(2),:));
        weights = [weights w];
    end

  
    G = graph(from,to,weights);   
    E = [from' to'];
    adj = adjacency(G);
    inc = incidence(G);

    nodes = numnodes(G);
    
    %Shortest paths:
    if shortest_path == true
        SPs_vec = ft_SPs;
        staircase_sum = @(x) 1/2*x*(x+1);
        start_ixs = zeros(1,max_no_of_hinges-1);
        for k = 1:(max_no_of_hinges-1)
            start_ixs(k) = staircase_sum(max_no_of_hinges-1)-staircase_sum(max_no_of_hinges-k)+1; 
        end
%         start_ixs = [1 8 14 19 23 26 28];
        for node = 1:(nH-1)
            targets = [node+1:nH];
            [~,SPs] = shortestpathtree(G,node,targets);
            SPs_vec(start_ixs(node):(start_ixs(node)+length(SPs)-1)) = SPs;
        end
        longest_path = max(SPs_vec);
    end
    
    
    %Centrality
    betweenness = centrality(G,'betweenness');
    degrees = centrality(G,'degree');
    closeness = centrality(G,'closeness');
    pagerank = centrality(G,'pagerank');
    eigenvector = centrality(G,'eigenvector');
    graph_density = nM/(1/2*nH*(nH-1));
    mean_graph_distance = mean(mean(grDistances(E)));
    graph_efficiency = 1-(mean_graph_distance/nM);

    %spanning tree
    eigenvalues_of_laplacian = eig(laplacian(G));

    no_of_spanning_trees = sum(eigenvalues_of_laplacian)/nM; %Kirchoff's theorem
    min_span_tree_members = grMinSpanTree(E);
    spectral_gap = min(eigenvalues_of_laplacian(eigenvalues_of_laplacian>0));
    Fiedler_value = min(eigenvalues_of_laplacian(eigenvalues_of_laplacian>spectral_gap));

    %radius eccentricity
    [eccentricity,radius,diameter,center_vertexes,periphere_vertexes]=grEccentricity(E);

    %planarity

    %cycles
    cycles = grCycleBasis(E);
    no_of_cycles = size(cycles,2);
    [length_max,cycle_ID_longest] = max(sum(cycles,1));         %Length max is replaced by true length instead of no.of.elements
    length_max = weights * cycles(:,cycle_ID_longest);
    part_of_longest = find(cycles(:,cycle_ID_longest));
    [length_min,cycle_ID_shortest] = min(sum(cycles,1));
    length_min = weights * cycles(:,cycle_ID_shortest);
    part_of_shortest = find(cycles(:,cycle_ID_shortest));       %length min is replaced by true length isntead of no.of.elements
    cluster_coef = ClusteringCoef(G);

    %% Creating features    
    ft_betweenness = init_ft_hinge;
    ft_betweenness(1:length(betweenness)) = betweenness/5;
    ft_degrees = init_ft_hinge;
    ft_degrees(1:length(degrees)) = degrees/max_no_of_hinges;
    ft_closeness = init_ft_hinge;
    ft_closeness(1:length(closeness)) = closeness;
    ft_pagerank = init_ft_hinge;
    ft_pagerank(1:length(pagerank)) = pagerank;
    ft_eigenvector = init_ft_hinge;
    ft_eigenvector(1:length(eigenvector)) = eigenvector;
    ft_graph_density = graph_density;
    ft_mean_graph_distance = mean_graph_distance/5;
    ft_graph_efficiency = graph_efficiency;
    ft_laplacian_eigenvalues = init_ft_hinge;
    ft_laplacian_eigenvalues(1:length(eigenvalues_of_laplacian)) = eigenvalues_of_laplacian/10;
    ft_no_of_spanning_trees = no_of_spanning_trees/5;
    ft_part_of_min_span_tree = init_ft_bar;
    ft_part_of_min_span_tree(min_span_tree_members) = 1;
    ft_spectral_gap = spectral_gap/5;
    ft_Fiedler_value = Fiedler_value/5;
    ft_eccentricity = init_ft_hinge;
    ft_eccentricity(1:length(eccentricity)) = eccentricity / 5;
    ft_radius = radius/5;
    ft_diameter = diameter/5;
    ft_part_of_center = init_ft_hinge;
    ft_part_of_center(center_vertexes) = 1;
    ft_part_of_periphery = init_ft_hinge;
    ft_part_of_periphery(periphere_vertexes) = 1;
    ft_no_of_cycles = no_of_cycles /5;
    ft_part_of_longest = init_ft_bar;
    ft_part_of_longest(part_of_longest) = 1;
    ft_part_of_shortest = init_ft_bar;
    ft_part_of_shortest(part_of_shortest) = 1;
    ft_longest_circle_length = length_max / 20;
    ft_shortest_circle_length = length_min / 20;
    ft_cluster_coef = init_ft_hinge;
    ft_cluster_coef(1:length(cluster_coef)) = cluster_coef;
    if shortest_path == true; ft_shortest_paths = SPs_vec ./ longest_path; else ft_shortest_paths = [];end
    
    graph_feature_vector =[ft_betweenness, ft_degrees, ft_closeness,...
        ft_pagerank, ft_eigenvector, ft_graph_density,...
        ft_mean_graph_distance, ft_graph_efficiency,...
        ft_laplacian_eigenvalues, ft_no_of_spanning_trees,...
        ft_part_of_min_span_tree, ft_spectral_gap, ft_Fiedler_value,...
        ft_eccentricity, ft_radius, ft_diameter, ft_part_of_center,...
        ft_part_of_periphery, ft_no_of_cycles, ft_part_of_longest, ...
        ft_part_of_shortest, ft_longest_circle_length,...
        ft_shortest_circle_length, ft_cluster_coef, ft_shortest_paths];
end
    
    
    

    
    
    
    
    
    
    
    
