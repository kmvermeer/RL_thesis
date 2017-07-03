%% Grid settings
gridlength = 10;
xgrid = 1:1:gridlength;
ygrid = xgrid;
[x y] = meshgrid(xgrid,ygrid);
gridxy = [x(:) y(:)];

%% Constants and Settings:
lr = 1;
evals = 500;
total_rotation = 2*pi;
max_no_of_hinges = 7;
max_no_of_bars = (max_no_of_hinges - 4)*2+4;


%% Initialize structure:

%Initialising:
h1 = [3,5];
h2 = [7,5];
h3 = [3,6];
h4 = [6,7];

H0 = [h1;h2;h3;h4];