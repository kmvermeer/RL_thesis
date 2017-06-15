%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%                                                                         %
%   Written by Reinier Kuppens as part of Msc Thesis                      %
%   Original Date: 29-06-2015                                             %
%                                                                         % 
%                                                                         %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%animateDNA(DNA,varargin) generates an animation of the mechanism described by DNA.
%
%   Input:  1)  DNA
%           2)  t   (optional)
%           3)  qss (optional)
%
%The time vector t and state matrix qss are optional. If not provided, the
%DNA will be numerically integrated and evaluated for fitness.
%
%   Output: 1)  mov (optional)
%           2)  map (optional)   
%
%The output can be used to create a .gif image of the animation:
%imwrite(mov,map,filename,'DelayTime',0,'LoopCount',inf)

%Make color of each component dependent on its mass.

function animateDNA(DNA,varargin)

%Check if t and qss are provided
if isempty(varargin)
    h = 0.05;
    T = 5;
    [t,qss]=simulateDNA_mex(DNA,T,h);
    [~,DNA.bestTrajectory]=fitnessFunction(DNA,t,qss,[]);
else
    t   = varargin{1};
    qss = varargin{2};
end


disp('You may want to adjust the window size in animateDNA.m')

figure_handle = figure('Color',[1 1 1],'Position', [50,50,1000,700],...
    'visible','on');            %Set background white
hold on
axis equal
axis([-10 10 -10 10])
% axis tight
% axis([0 6 -1 5])
xlabel('Distance [m]')
ylabel('Distance [m]')
axis on
grid on 
ht = title(sprintf('Time: %0.2f sec', t(1))); %Print time in title

[massPoints,comPoint] = getMassLocations3(DNA);

nM      = numel(massPoints);
cdata   = rand(nM,3);
R       = @(angle) [cos(angle),-sin(angle);sin(angle),cos(angle)];

plotGrounds(DNA);

[Pground,Pgroundc]   = getGroundP(DNA,'P');
[Pmground,Pmgroundc] = getGroundP(DNA,'Pm');
 
nP  = numel(Pground);
nPm = numel(Pmground);

for k = 1:nP
    Pgroundh{k}  = fill(Pground{k}(1,:),Pground{k}(2,:),[0.2,0.2,0.2]);
    Pgroundch{k} = fill(Pgroundc{k}(1,:),Pgroundc{k}(2,:),'w','Linewidth',2);
end
for k = 1:nPm
    Pmgroundh{k}  = fill(Pmground{k}(1,:),Pmground{k}(2,:),[1,1,0.2]);
    Pmgroundch{k} = fill(Pmgroundc{k}(1,:),Pmgroundc{k}(2,:),'w','Linewidth',2);
end



%Get the initial outline of the parts with the centre of mass point
for k = 1:nM
    [x1{k},y1{k},x2{k},y2{k},x3{k},y3{k}] = getComOutline(comPoint{k}); %ROW VECTORS
    [polx{k},poly{k},scx{k},scy{k}] = getMassOutline(massPoints{k}); %ROW VECTORS
end

%Draw all masses and create plot handles
for k =1:nM
    polh(k)=fill(polx{k},poly{k},cdata(k,:),'Edgecolor','none');
    alpha(0.5)
end

%Draw all com points and create plot handles
for k =1:nM
    comh1(k)=fill(x3{k},y3{k},'w');
    comh2(k)=plot(x3{k},y3{k},'k');
    comh3(k)=fill(x1{k},y1{k},'k');
    comh4(k)=fill(x2{k},y2{k},'k');
    for l =1:numel(scx{k})
        polh2(k,l)=fill(scx{k}{l},scy{k}{l},'w','Linewidth',2);
    end
end

%Plot the trajectory
% trajecth = plot(DNA.bestTrajectory(1,1),DNA.bestTrajectory(1,2),'g.','markersize',10);
plot(DNA.bestTrajectory(:,1),DNA.bestTrajectory(:,2),'-r')




sSDNA   = size(DNA.Spar);
nS      = sSDNA(2);
incS    = DNA2inc(DNA,'S');


if nS>0
    [xs,ys,nCoils,maxL,distUncoiled] = getSpringOutline(DNA);
    for k = 1:nS
        springh(k) = plot(xs{k},ys{k},'k','Linewidth',1);
    end
end

% nFrames = max(t)*25;
% nSkip   = floor(numel(t)/nFrames);
% nt      = 1:nSkip:numel(t);

%Set data for imwrite
 pos     = get(gcf, 'Position');
 width   = pos(3);
 height  = pos(4);
 

 
mov     = zeros(height, width, 1, length(t), 'uint8');

% counterPic=1;
mCounter = 1;

for ii = 1:length(t)
    
    %         set(trajecth,'Xdata',DNA.bestTrajectory(ii,1),'Ydata',DNA.bestTrajectory(ii,2))
    set(ht, 'String', sprintf('Time: %0.2f sec', t(ii)))
    
    
    %Move the grounds for the linear hinges. 
    Pidx = find(DNA.edgelabel==3);
    Pmidx = find(DNA.edgelabel==4);

    inc  = DNA2inc(DNA,'all');
    cnt = 1;
    
%      keyboard 
    for k = 1:nP
         
        Pmasses = find(inc(:,Pidx(k))==1);
        Pmasses = Pmasses(2)-1;
        
        %Determine the location of the hinge
        PpointR = R(qss(ii,Pmasses*3))*[  DNA.Ppar(1,k)-comPoint{Pmasses}(1);       
                                          DNA.Ppar(2,k)-comPoint{Pmasses}(2)];
        PpointRT = bsxfun(@plus,PpointR,[qss(ii,Pmasses*3-2);qss(ii,Pmasses*3-1)]);       
                
        %Add computed location to the ground location minus its original
        %location
        PgroundDataRT = [   Pground{k}(1,:)+PpointRT(1)-DNA.Ppar(1,k);
                            Pground{k}(2,:)+PpointRT(2)-DNA.Ppar(2,k)];
                    
        PgroundcDataRT = [  Pgroundc{k}(1,:)+PpointRT(1)-DNA.Ppar(1,k);
                            Pgroundc{k}(2,:)+PpointRT(2)-DNA.Ppar(2,k)];
        
        set(Pgroundh{k},'Xdata',PgroundDataRT(1,:),'Ydata',PgroundDataRT(2,:));
        set(Pgroundch{k},'Xdata',PgroundcDataRT(1,:),'Ydata',PgroundcDataRT(2,:));
        
        cnt = cnt + 1;
    end
    
    for k = 1:nPm
         
        Pmasses = find(inc(:,Pmidx(k))==1);
        Pmasses = Pmasses(2)-1;
        
        %Determine the location of the hinge
        PpointR = R(qss(ii,Pmasses*3))*[  DNA.Pmpar(1,k)-comPoint{Pmasses}(1);       
                                          DNA.Pmpar(2,k)-comPoint{Pmasses}(2)];
        PpointRT = bsxfun(@plus,PpointR,[qss(ii,Pmasses*3-2);qss(ii,Pmasses*3-1)]);       
                
        %Add computed location to the ground location minus its original
        %location
        PmgroundDataRT = [   Pmground{k}(1,:)+PpointRT(1)-DNA.Pmpar(1,k);
                            Pmground{k}(2,:)+PpointRT(2)-DNA.Pmpar(2,k)];
                    
        PmgroundcDataRT = [  Pmgroundc{k}(1,:)+PpointRT(1)-DNA.Pmpar(1,k);
                            Pmgroundc{k}(2,:)+PpointRT(2)-DNA.Pmpar(2,k)];
        
        set(Pmgroundh{k},'Xdata',PmgroundDataRT(1,:),'Ydata',PmgroundDataRT(2,:));
        set(Pmgroundch{k},'Xdata',PmgroundcDataRT(1,:),'Ydata',PmgroundcDataRT(2,:));
        
        cnt = cnt + 1;
    end
    
%     keyboard 
    %Move the masses
    for k =1:nM
        
        RpolhData = R(qss(ii,k*3))*[polx{k}-comPoint{k}(1);poly{k}-comPoint{k}(2)];
        RTpolhData = bsxfun(@plus,RpolhData,[qss(ii,k*3-2);qss(ii,k*3-1)]);
        set(polh(k),'Xdata',RTpolhData(1,:),'Ydata',RTpolhData(2,:))
        
    end
    
    %Move the grounds
    
    for k =1:nM
        Rx1Data = R(qss(ii,k*3))*[x1{k}-comPoint{k}(1);y1{k}-comPoint{k}(2)];
        RTx1Data = bsxfun(@plus,Rx1Data,[qss(ii,k*3-2);qss(ii,k*3-1)]);
        
        Rx2Data = R(qss(ii,k*3))*[x2{k}-comPoint{k}(1);y2{k}-comPoint{k}(2)];
        RTx2Data = bsxfun(@plus,Rx2Data,[qss(ii,k*3-2);qss(ii,k*3-1)]);
        
        Rx3Data = R(qss(ii,k*3))*[x3{k}-comPoint{k}(1);y3{k}-comPoint{k}(2)];
        RTx3Data = bsxfun(@plus,Rx3Data,[qss(ii,k*3-2);qss(ii,k*3-1)]);
        
        set(comh1(k),'Xdata',RTx3Data(1,:),'Ydata',RTx3Data(2,:))
        set(comh2(k),'Xdata',RTx3Data(1,:),'Ydata',RTx3Data(2,:))
        set(comh3(k),'Xdata',RTx1Data(1,:),'Ydata',RTx1Data(2,:))
        set(comh4(k),'Xdata',RTx2Data(1,:),'Ydata',RTx2Data(2,:))
        
        for l =1:numel(scx{k})
            Rpolh2Data{l}= R(qss(ii,k*3))*[scx{k}{l}-comPoint{k}(1);scy{k}{l}-comPoint{k}(2)];
            RTpolh2Data{l} = bsxfun(@plus,Rpolh2Data{l},[qss(ii,k*3-2);qss(ii,k*3-1)]);
            
            set(polh2(k,l),'Xdata',RTpolh2Data{l}(1,:),'Ydata',RTpolh2Data{l}(2,:))
        end
    end
    
    for k=1:nS
        
        
        massnr = find(incS(:,k)==1);    %Find entries in column
        
        if any(massnr==1)
            mnr = massnr(2)-1;
            
            com            = comPoint{mnr}.';
            origo{k}       = DNA.Spar(1:2,k);
            insertie{k}    = R(qss(ii,mnr*3))*(DNA.Spar(3:4,k)-com) + [qss(ii,mnr*3-2);qss(ii,mnr*3-1)];
            
            [x{k} y{k}] = springcoord(origo{k},insertie{k},nCoils(k),maxL(k),distUncoiled(k));
            
            set(springh(k),'Xdata',x{k},'Ydata',y{k})
            
            
            
        else
            mnr1 = massnr(1)-1;
            mnr2 = massnr(2)-1;
            
            com1 = comPoint{mnr1}.';
            com2 = comPoint{mnr2}.';
            
            origo{k}    = R(qss(ii,mnr1*3))*(DNA.Spar(1:2,k)-com1)+[qss(ii,mnr1*3-2);qss(ii,mnr1*3-1)];
            insertie{k} = R(qss(ii,mnr2*3))*(DNA.Spar(3:4,k)-com2)+[qss(ii,mnr2*3-2);qss(ii,mnr2*3-1)];
            
            [x{k} y{k}] = springcoord(origo{k},insertie{k},nCoils(k),maxL(k),distUncoiled(k));
            
            set(springh(k),'Xdata',x{k},'Ydata',y{k})
            
        end
        
    end
    
    f=getframe(gcf);
    
%     keyboard
%     if mCounter == 1
%         [mov(:,:,1,mCounter), map] = rgb2ind(f.cdata, 256, 'nodither');
%     else
%         mov(:,:,1,mCounter) = rgb2ind(f.cdata, map, 'nodither');
%     end
%     
    mCounter = mCounter+1;

    %Save each frame to eps
    %     if mod(ii,2)==0
    %         savename = ['frames\frame',num2str(counterPic),'.pdf'];
    %         saveas(figure_handle,savename);%'epsc'
    %         counterPic=counterPic+1;
    %     end
    
end

animation_name = strcat('Animation','.gif');
% Create animated GIF
% imwrite(mov, map,animation_name, 'DelayTime', 0, 'LoopCount', inf);

end%Function




