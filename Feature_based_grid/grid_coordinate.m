function [coordinate] = grid_coordinate(point,gridxy,type)
	no_of_gridpoints = size(gridxy,1);
    n = sqrt(no_of_gridpoints);
    if strcmp(type,'to')
        point_x = point(1);
        point_y = point(2);
        coordinate = point_x+n*(point_y-1);
    elseif strcmp(type,'from')
        col = mod(point,n);
        row = (point-col)/n+1;
        coordinate = [col, row];  
    end
end

