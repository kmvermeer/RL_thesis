function [I,H,s] = initIH()
    settings_file;
    TDlist = '';
    linklist = [];
    [I,H] = build_mech(H0,TDlist,linklist);
    s = get_state(I,H);
end