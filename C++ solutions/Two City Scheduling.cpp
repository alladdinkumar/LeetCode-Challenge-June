class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int curr_cost=0,cnta=0,cntb=0;
        map<int,int> a,b;
        int n=costs.size()/2;
        for(auto i:costs)
        {
            if(i[0]<=i[1] && cnta<n)
            {
                curr_cost+=i[0];
                cnta++;
                a[i[1]-i[0]]++;
                
            }
            else if(i[0]>=i[1] && cntb<n)
            {
                curr_cost+=i[1];
                cntb++;
                b[i[0]-i[1]]++;
               
            }
            else if(i[0]>i[1] && cntb==n)
            {
                auto x=b.begin();
                int tmp=curr_cost+ x->first;
                if(tmp+i[1] < curr_cost+i[0])
                {
                    a[-x->first]++;
                    if(x->second==1)
                        b.erase(x);
                    else
                        b[x->first]--;
                    cnta++;
                    curr_cost=tmp+i[1];
                    b[i[0]-i[1]]++;
                   
                }
                else
                {
                    curr_cost+=i[0];
                    cnta++;
                    a[i[1]-i[0]]++;
                   
                }
            }
            else if(i[0]<i[1] && cnta==n)
            {
                auto x=a.begin();
                int tmp=curr_cost+x->first;
                if(tmp+i[0] <curr_cost+i[1])
                {
                    b[-x->first]++;
                    if(x->second==1)
                        a.erase(x);
                    else
                        a[x->first]--;
                    curr_cost=tmp+i[0];
                    cntb++;
                    a[i[1]-i[0]]++;
                   
                }
                else
                {
                    curr_cost+=i[1];
                    cntb++;
                    b[i[0]-i[1]]++;
                }
            }
        }
        return curr_cost;
    }
};
