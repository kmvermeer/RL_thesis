function [I,H] = random_init(no_of_operations)
   
    addpath /Users/kazv/Documents/TU/Thesis/MATLAB/evaluation_using_FEM/
    addpath /Users/kazv/Documents/TU/Thesis/MATLAB/Hod_operators/

    random_ints = randi(2,1,no_of_operations);
    TDlist = '';
    linklist = zeros(1,no_of_operations);
    nM = 3;

    for i = 1:no_of_operations
        link = randi(nM,1,1);
        linklist(i) = link;
        if random_ints(i) == 1
            TDlist = strcat(TDlist,'D');
            nM = nM+2;
        else
            TDlist = strcat(TDlist,'T');
            nM = nM+1;
        end

    end
    disp(TDlist)
    disp(linklist)
    %Initialising:
    h1 = [0,0];
    h2 = [4,0];
    h3 = [0,1];
    h4 = [3,2];

    H0 = [h1;h2;h3;h4];
    % TDlist = 'DDTDTDDT';
    % linklist = [3,3,1,3,4,5,8,6,4,4];

    [I,H,M] = build_mech(H0,TDlist,linklist);
    nM = size(M,1);
    nH = size(H,1);
    plot_mech(I,H);
end

%Just adding some random commentsddd