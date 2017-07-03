function [I,H] = state2IH(s)
    settings_file

    incidence_info = s(1:max_no_of_bars);
    hinge_info = s(max_no_of_bars:end);


    incidence_vector = incidence_info(incidence_info~= 0);
    I = zeros(max_no_of_bars,max_no_of_hinges);

    for k = 1:length(incidence_vector)
        I_row = zeros(1,max_no_of_hinges);
        if incidence_vector(k) ~= 0
            I_from_incidence = str2I(incidence_vector(k));
            I_row(1:length(I_from_incidence)) = I_from_incidence;
        end
        I(k,:) = I_row;
    end

    [rows,cols] = find(I);
    I = I(1:max(rows),1:max(cols));


    hinges = hinge_info(hinge_info~=0);
    H_free = [];
    for j = 1:length(hinges)
        H_row = grid_coordinate(hinges(j),gridxy,'from');
        H_free= [H_free;H_row];
    end
    H = [H0(1:2,:);H_free];
end
    
