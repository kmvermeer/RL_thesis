function s = get_state(I,H)
    settings_file;
    max_no_of_bars = (max_no_of_hinges - 4)*2+4;
    incident_vector = zeros(1,max_no_of_bars);
    nM = size(I,1);
    nH = size(I,2);
    
    if size(I,1) <= max_no_of_bars
        stateI = zeros(max_no_of_bars,max_no_of_hinges);
        stateH = stateI;
        stateI(1:nM,1:nH) = I;
        stateH(1:2,1:nH) = H';
    else
        stateI = I;
        stateH = zeros(size(stateI));
        stateH(1:2,:) = H';
    end
    
    s = [stateI stateH];
    %State vector shows incident numbers from bar 2 untill the  last bar. 
    %The other numbes are the grid locations of points 4 and upwards.
       
end