class Solution {
    vector<vector<int>>dist;
    unordered_map<int,vector<int>>m;
    int cost;
    int d;
    int k;
public:
    void bfs(int src)
    {
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,0}});
        while(!q.empty())
        {
            int curr_node=q.front().first;
            int t_cost=q.front().second.first;
            int stop=q.front().second.second;
            q.pop();
            for(auto next:m[curr_node])
            {
                if(next==d)
                   cost= cost > (t_cost+dist[curr_node][d])? (t_cost+dist[curr_node][d]) :cost;
                else if(stop<k && t_cost+dist[curr_node][next]<cost)
                {
                    q.push({next,{t_cost+dist[curr_node][next],stop+1}});
                }
            }
        }
                            
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        dist=vector<vector<int>>(n,vector<int>(n,INT_MAX));
        d=dst;
        k=K;
        for(auto x : flights)
        {
           dist[x[0]][x[1]]=x[2]; 
           m[x[0]].push_back(x[1]);
        }
        cost=dist[src][dst];
        bfs(src);
        return cost==INT_MAX?-1:cost;
    }
};
