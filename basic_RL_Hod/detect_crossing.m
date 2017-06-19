function [cross_list] = detect_crossing(I,H,link,new_line)
%Function performs a check for crossings between the current mechanism
%and a new line. Returns list denoting links numbers that cross 
% with new_line. The link number in 'link' is neglected.

%Written by K.M. Vermeer

    X1 = new_line(1);
    Y1 = new_line(2);
    X2 = new_line(3);
    Y2 = new_line(4);

    x1 = min([X1,X2]);
    x2 = max([X1,X2]);
    y1 = min([Y1,Y2]);
    y2 = max([Y1,Y2]);

    v = [X1,Y1]';
    s = [X2-X1,Y2-Y1]';
    nM = size(I,1);
    potential_cross_list = [];

    for i = 1:nM
        mtrans = H(get_connections(I,i,'bar'),:);
        m = mtrans';
        m = m(:)';
        xm1 = min([m(1),m(3)]);
        xm2 = max([m(1),m(3)]);
        ym1 = min([m(2),m(4)]);
        ym2 = max([m(2),m(4)]);

        nocross_biggerx = xm1>=x2;
        nocross_smallerx = xm2<=x1;
        nocross_biggery = ym1>=y2;
        nocross_smallery = ym2<=y1;

        nocrossing = nocross_biggerx|nocross_smallerx|nocross_biggery|nocross_smallery;

        if(not(nocrossing))
            potential_cross_list = [potential_cross_list,i] ;
        end
    end

    potential_cross_list(potential_cross_list == link)=[];
    cross_list = [];
    cross2d = @(a,b) a(1)*b(2) - a(2)*b(1);

    for k = 1:numel(potential_cross_list)
        crosser = potential_cross_list(k);
        nodes = H(get_connections(I,crosser,'bar'),:);
        xcr1 = nodes(1);
        xcr2 = nodes(2);
        ycr1 = nodes(3);
        ycr2 = nodes(4);
    

        u = [xcr1,ycr1]';
        r = [xcr2-xcr1,ycr2-ycr1]';
        %http://stackoverflow.com/questions/563198/
        %how-do-you-detect-where-two-line-segments-intersect
        t = cross2d((v-u),s)/cross2d(r,s);
        if(0<abs(t) && abs(t)<1)
            cross_list = [cross_list, k];
        end
    end
end