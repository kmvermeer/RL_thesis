function [str] = I2str(I)
    nH = size(I,2);
    str = [];
    for H = 1:nH
        node = find(I(:,H));
        from = node(1);
        to = node(2);
        display([from,to])
        inc = from*(from+1)/2 +to;
        str = [str, inc];
    end
end
