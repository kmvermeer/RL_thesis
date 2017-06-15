function [connections] = get_connections(I,element_no,type)
    if strcmp(type,'hinge')
        connections = find(I(:,element_no));
    elseif strcmp(type,'bar')
        connections = find(I(element_no,:));
    else
        error('Unknown element type: %s',type);
   
end
end