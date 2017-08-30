

lr = 0.2
type = 'Adams'
styles = [{'Sigmoid','linear'},{'leaky_ReLU','linear'}]
styles = styles(3:4)
hidden_multiplier = 4;
max_error = 1e-3;
max_epochs = 5000;
[weights,error_list,Qlist_all,alist_all,total_rewards] = main_NN_function(lr,type,styles,hidden_multiplier,max_error,max_epochs)