%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


function [D,Dq,Dqq,Dt,Dqt,Dtt] = getDk(t,state,DNA)

comPoints = getCompoints(DNA);    %Get the centre of mass points

nM   = numel(DNA.Mpar(:,1))-1;    %Number of masses

nH   = sum(DNA.edgelabel==1);     %Number of hinges
nP   = sum(DNA.edgelabel==3);
nPm  = sum(DNA.edgelabel==4);

%If you are going to mex simulateDNA you should uncomment the next line,
%and comment the line above.
incH    = DNA2inc(DNA,'H');          %Get incidence matrix
incP    = DNA2inc(DNA,'P');
incPm   = DNA2inc(DNA,'Pm');

nC = nH*2+nP+nPm*2;                   %The number of constraints

D    = zeros(nC,1);                 %For scleronomic constraints
Dq   = zeros(nC,nM*3);
Dqq  = zeros(nC,1);

Dt  = zeros(nC,1);                  %Extra for rheonomic constraints
Dqt = zeros(nC,1);
Dtt = zeros(nC,1);

X  = state(1:numel(state)/2).'; 
Xd = state(numel(state)/2+1:end).';
  
%For rotational joint
cnr = 1;
for k = 1:nH
    massnr = find(incH(:,k)==1);    %Find entries in column
    
    if any(massnr==1)               %If this column contains ground
        mnr = massnr(2)-1;
        
        H = DNA.Hpar(:,k);
        com = comPoints(mnr,:).';
        mx = X(mnr*3-2:mnr*3).';
        mxd = Xd(mnr*3-2:mnr*3).';
        
        D(cnr:cnr+1,1) = MGH(H,com,mx);
        if nargout>1
            Dq(cnr:cnr+1,mnr*3-2:mnr*3) = MGH_q(H,com,mx);
        end
        if nargout>2
            Dqq(cnr:cnr+1,1) = MGH_qq(H,com,mx,mxd);
        end
        cnr = cnr+2;
    else
        mnr1 = massnr(1)-1;
        mnr2 = massnr(2)-1;
        
        H = DNA.Hpar(:,k);
        com1 = comPoints(mnr1,:).';
        com2 = comPoints(mnr2,:).';
        mx   = [X(mnr1*3-2:mnr1*3) X(mnr2*3-2:mnr2*3)].';
        mxd = [Xd(mnr1*3-2:mnr1*3) Xd(mnr2*3-2:mnr2*3)].';
        
        D(cnr:cnr+1,1) = MMH(H,com1,com2,mx);                 %Constraints
        if nargout>1
            MMHconstraintd = MMH_q(H,com1,com2,mx);                  %Derivative of constraints
            Dq(cnr:cnr+1,mnr1*3-2:mnr1*3) = MMHconstraintd(:,1:3);
            Dq(cnr:cnr+1,mnr2*3-2:mnr2*3) = MMHconstraintd(:,4:6);
        end
        if nargout>2
            Dqq(cnr:cnr+1,1) = MMH_qq(H,com1,com2,mx,mxd);        %Double derivative of constraints
        end
        cnr = cnr+2;
    end
end

%For prismatic Joints

for k = 1:nP
    massnr = find(incP(:,k)==1);    %Find entries in column
    
    if any(massnr==1)               %If this column contains ground
        mnr = massnr(2)-1;
        
        H = DNA.Ppar(1:2,k);
        alpha = DNA.Ppar(3,k);
          
        com = comPoints(mnr,:).';
        mx = X(mnr*3-2:mnr*3).';
        mxd = Xd(mnr*3-2:mnr*3).';
         
        D(cnr,1) = MGP(H,alpha,com,mx);
        if nargout>1
            Dq(cnr,mnr*3-2:mnr*3) = MGP_q(H,alpha,com,mx);
        end
        if nargout>2
            Dqq(cnr,1) = MGP_qq(H,alpha,com,mx,mxd);
        end
        
        cnr = cnr+1;
        
    else
        error('You can only use edge 3, i.e. pendulum on cart, if it is connected to a ground') 
    end
end

%For prismatic Joints

for k = 1:nPm
    massnr = find(incPm(:,k)==1);    %Find entries in column
    
    if any(massnr==1)               %If this column contains ground
        mnr = massnr(2)-1;
        
        H       = DNA.Pmpar(1:2,k);
        alpha   = DNA.Pmpar(3,k);
        a       = DNA.Pmpar(4,k);
        w       = DNA.Pmpar(5,k);
          
         
%         keyboard 
        com     = comPoints(mnr,:).';
        mx      = X(mnr*3-2:mnr*3).';
        mxd     = Xd(mnr*3-2:mnr*3).';
        
        cnrIdx = cnr:cnr+1;
%          keyboard 
        D(cnrIdx,1) = MGPm(H,alpha,a,w,com,t,mx);
        if nargout>1
                Dq(cnrIdx,mnr*3-2:mnr*3) = MGPm_q(H,alpha,a,w,com,t,mx);
        end
        if nargout>2
                Dqq(cnrIdx,1) = MGPm_qq(H,alpha,a,w,com,t,mx,mxd);
        end
        if nargout>3
                Dt(cnrIdx,1)  = MGPm_t(H,alpha,a,w,com,t,mx);
        end
        if nargout>4
                Dqt(cnrIdx,1) = MGPm_qt(H,alpha,a,w,com,t,mx,mxd);
        end
        if nargout>5
                Dtt(cnrIdx,1) = MGPm_tt(H,alpha,a,w,com,t,mx);
        end
% keyboard 
        cnr = cnr+2;
        
    else
        error('You can only use edge 3, i.e. pendulum on cart, if it is connected to a ground') 
    end
end


 

end