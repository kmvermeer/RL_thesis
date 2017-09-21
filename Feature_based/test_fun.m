% Ft = F;
% 
% %F(74) =.75
% tiny = .001;
% k74 = 0:.001:2;
% Q = eval_NN(weights,F,layer_settings,true);
% sens_k74 = zeros(size(k74));
% for i = 1:length(k74);
%     Ft(74) = k74(i);
%     Qt = eval_NN(weights,Ft,layer_settings,true);
%     Q_k74(i) = Qt;
% end
%     
