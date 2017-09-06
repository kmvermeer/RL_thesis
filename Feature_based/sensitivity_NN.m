input = F;
nF = size(F,2);
output = eval_NN(weights,input,layer_settings,true);
sens = zeros(1,nF);
delta = 0.01;
for k = 1:nF
    Fpos = F;
    Fpos(k) = Fpos(k)+delta;
    Fmin = F;
    Fmin(k) = Fmin(k)-delta;
    Q_dpos = eval_NN(weights,Fpos,layer_settings,true);
    Q_dmin = eval_NN(weights,Fmin,layer_settings,true);
    sens(k) = (Q_dpos - Q_dmin) / (2*delta);
    sens(F == 0) = 0;
end

bar(sens)
title('Q-value sensitivity wrt features')
grid on
ylim([1.1*min(sens),1.1*max(sens)])


    