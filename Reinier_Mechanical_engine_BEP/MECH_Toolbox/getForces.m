%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function F = getForces(t,state,DNA)

% nX  = length(state)/2;              %Get the number of coordinates
% X  = state(1:nX);
% Xd = state(nX+1:end);               %Get the velocity vector

X  = state(1:numel(state)/2).'; 
Xd = state(numel(state)/2+1:end).';

comPoint = getCompoints(DNA);
mass    = DNA.Mpar(2:end,3);                            %Mass of bodies

g  = 9.81;
nM = numel(DNA.Mpar(:,1))-1;


nH  = sum(DNA.edgelabel==1);
nS  = sum(DNA.edgelabel==2);     %Number of springs


incH = DNA2inc(DNA,'H');
incS = DNA2inc(DNA,'S');


Fs = zeros(3*nM,1);
Fh = zeros(3*nM,1);

%Set torsion springs and hinge friction
for k = 1:nH
    
    massnr = find(incH(:,k)==1);
    K = DNA.Hpar(3,k);
    C = DNA.Hpar(4,k);
    theta0 = DNA.Hpar(5,k);
    
    if any(massnr==1)
        mnr = massnr(2)-1; %account for ground
        
        MGST = MGtorsion(K,theta0,[X(mnr*3-2) ;X(mnr*3-1) ;X(mnr*3)]);   %Torsion Spring
        MGDT = MGtorsion(C,theta0,[Xd(mnr*3-2);Xd(mnr*3-1);Xd(mnr*3)]);  %Hinge Damping
        
        Fh(mnr*3-2:mnr*3,1) = Fh(mnr*3-2:mnr*3,1) + MGST + MGDT;

    else
        mnr1 = massnr(1)-1;
        mnr2 = massnr(2)-1;
            
        MMST = MMtorsion(K,theta0,[X(mnr1*3-2); X(mnr1*3-1); X(mnr1*3);  %Torsion spring
                                   X(mnr2*3-2); X(mnr2*3-1); X(mnr2*3)]);
                                
        MMDT = MMtorsion(C,0,[Xd(mnr1*3-2);Xd(mnr1*3-1);Xd(mnr1*3);  %Hinge Damping
                              Xd(mnr2*3-2);Xd(mnr2*3-1);Xd(mnr2*3)]);
                        
        
        Fh(mnr1*3-2:mnr1*3,1) = Fh(mnr1*3-2:mnr1*3,1) + MMST(1:3,1) + MMDT(1:3,1);
        Fh(mnr2*3-2:mnr2*3,1) = Fh(mnr2*3-2:mnr2*3,1) + MMST(4:6,1) + MMDT(4:6,1);
        
%         Fh(mnr2*3,1) = -(X(mnr2*3)-X(mnr1*3))*DNA.Hpar(3,k)-(Xd(mnr2*3)-Xd(mnr1*3))*DNA.Hpar(4,k);
    end
end




for k = 1:nS
    
    massnr = find(incS(:,k)==1);    %Find entries in column
    
    ps1 = DNA.Spar(1:2,k);
    ps2 = DNA.Spar(3:4,k);
    L0 = DNA.Spar(5,k);
    K  = DNA.Spar(6,k);
    
    if any(massnr==1)   %account for ground
        
        mnr = massnr(2)-1;
        com = comPoint(mnr,:).';

        MGSF = MGspringforce(ps1,ps2,L0,K,com,[state(mnr*3-2);state(mnr*3-1);state(mnr*3)]);
        Fs(mnr*3-2:mnr*3,1) = Fs(mnr*3-2:mnr*3,1) + MGSF;

    else
        
        mnr1 = massnr(1)-1;
        mnr2 = massnr(2)-1;
        com1 = comPoint(mnr1,:).';
        com2 = comPoint(mnr2,:).';
        

        MMSF = MMspringforce(ps1,ps2,L0,K,com1,com2,[state(mnr1*3-2);state(mnr1*3-1);state(mnr1*3);
                                                     state(mnr2*3-2);state(mnr2*3-1);state(mnr2*3)]);
        
        Fs(mnr1*3-2:mnr1*3,1) = Fs(mnr1*3-2:mnr1*3,1) + MMSF(1:3,1);
        Fs(mnr2*3-2:mnr2*3,1) = Fs(mnr2*3-2:mnr2*3,1) + MMSF(4:6,1);
    end
end

Fapply = zeros(3*nM,1);
if 2<t&&t<4
    for k = 1:nM
        Fapply(k*3)=0;
    end
end



Fg = zeros(3*nM,1);
for k =1:nM
    Fg(k*3-1) = -mass(k)*g;
end

F = Fg+Fs+Fh+Fapply;
