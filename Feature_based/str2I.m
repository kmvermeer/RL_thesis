function [I_row] = str2I(inc)

    %Determining min and max values for v1 according to Kuppens 3.19
    upper = floor(sqrt(2*inc)+3);
    lower = ceil(sqrt(2*inc));
    solution = [];

    %Determining all possible solution for v2
    for v1 = lower:upper
        if v1~=2
                combination = nchoosek(v1-1,2);
            else
                combination = 0;
        end

        v2 = inc - combination;
        solution = [solution;v1,v2];
    end
    
    %Select only viable solution where v1>v2>0
    solution = solution(solution(:,1)>solution(:,2),:);
    solution = solution(solution(:,1)>0,:);
    solution = solution(solution(:,2)>0,:);
    
    %Turn solution into minimal I_row
    I_row = zeros(1,max(solution));
    I_row(solution) = 1;
end
