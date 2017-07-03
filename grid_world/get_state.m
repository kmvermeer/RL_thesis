function s = get_state(I,H,gridxy,max_no_of_hinges)
    
    max_no_of_bars = (max_no_of_hinges - 4)*2+4;
    incident_vector = zeros(1,max_no_of_bars);
    hinge_grid_locations = zeros(1,max_no_of_hinges);
    
    for i = 1:size(H,1)
        hinge = H(i,:);
        hinge_grid_locations(i) = grid_coordinate(hinge,gridxy,'to');
    end
    
   incidents = I2str(I)';
   incident_vector(1:length(incidents)) = sort(incidents);
   
   
 
   
   s = [incident_vector(1:end) hinge_grid_locations(3:end)];
    %State vector shows incident numbers from bar 2 untill the  last bar. 
    %The other numbes are the grid locations of points 4 and upwards.
       
end