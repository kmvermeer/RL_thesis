function [I,H,s] = initIH(max_no_of_hinges,max_no_of_bars)
    settings_file;
    TDlist = '';
    linklist = [];
    [I,H] = build_mech(H0,TDlist,linklist);
    s = get_state(I,H,max_no_of_hinges,max_no_of_bars);
end