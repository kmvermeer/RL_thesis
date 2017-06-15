function value=new_card(force_black)
    number = floor(rand(1)*10+1);
    color_gen = rand(1);
    
    if force_black == 1
        color_gen = 0;
    end

    if color_gen>2/3
        value = -number;
    else
        value = number;
    end
           
end
