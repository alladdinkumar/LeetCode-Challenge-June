class Solution {
    unordered_map<string,vector<string>>flights;
    vector<string>path;
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t : tickets){
            flights[t[0]].push_back(t[1]);
        }
        for(auto itr=flights.begin();itr!=flights.end();itr++)
        {
            sort(itr->second.begin(),itr->second.end());
        }
        dfs("JFK");
        return path;
    }
    void dfs(string departure){ 
        while(flights.find(departure)!=flights.end() && flights[departure].size() > 0){
            string s =flights[departure][0];
            flights[departure].erase(flights[departure].begin());
            dfs(s);
        }
        path.insert(path.begin(),departure);
    }
};
