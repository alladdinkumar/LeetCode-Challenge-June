class Solution {
public:
    string validIPAddress(string IP) {
        if(IP.find(":")==-1)
        {
            stringstream ss(IP);
            int cnt=0;
            while(ss.good())
            {
                string part;
                getline(ss,part,'.');
                cnt++;
                if(part.length()>3 || part.empty() || (part.length() >1 && part[0]=='0'))
                    return "Neither";
                for(char c:part)
                    if(!isdigit(c) )
                        return "Neither";
                int num=stoi(part);
                if(num<0 || num>255)
                    return "Neither";
            }
            if(cnt==4)
                return "IPv4";
            return "Neither";
        }
        else
        {
            stringstream ss(IP);
            int cnt=0;
            while(ss.good())
            {
                string part;
                getline(ss,part,':');
                cnt++;
                if(cnt>8 || part.length()>4 || part.empty() )
                    return "Neither";
                for(char c:part)
                    if(!isdigit(c) && !(c>='a' && c<='f') && !(c>='A' && c<='F')  )
                        return "Neither";
            }
            if(cnt==8)
                return "IPv6";
            return "Neither";
        }
    }
};
