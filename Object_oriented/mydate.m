classdef mydate
%description goes here
    properties
    %properties go here
        minute = 0;
        hour;
        day;
        month;
        year;
    end
    
    methods
    %Describes methods
        
        function obj=mydate(minute,hour,day,month,year)
        %class constructor
            if(nargin>0)
                obj.minute = minute;
                obj.hour = hour;
                obj.day= day;
                obj.month = month;
                obj.year = year;
            end
        
        end
        
        function obj = rollDay(obj,numdays)
            
            obj.day = obj.day+numdays;
        end
        
        
    end
     methods(Static = true)
        function printCurrentDate()
            display(datestr(now));
        end
    end

end


               
        