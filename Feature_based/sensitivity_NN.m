close all
input = F;
nF = size(F,2);
output = eval_NN(weights,input,layer_settings,true);
sens = zeros(1,nF);
delta = .01;
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
figure
bar(sens)
title('Q-value sensitivity wrt features')
grid on
ylim([1.1*min(sens),1.1*max(sens)])

Qs = zeros(1,2*max_no_of_bars);
for a = 1:2*max_no_of_bars
    F = get_features(s,a);
    Qs(a) = eval_NN(weights,F,layer_settings,true);
    
end
max(Qs)
figure;
bar(Qs);
title('Q-value sensitivity wrt action choice')
grid on
xlabel('Action choice')
xticks([1:24])
xticklabels({'D1','T1','D2','T2','D3','T3','D4','T4','D5','T5','D6','T6',...
    'D7','T7','D8','T8','D9','T9','D10','T10','D11','T11','D12','T12'})
ylabel('Q-value')


    