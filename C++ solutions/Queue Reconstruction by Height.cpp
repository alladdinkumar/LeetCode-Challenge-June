class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),[](auto a,auto b){return (a[0]>b[0] || (a[0]==b[0] && a[1]<b[1]));});
        vector<vector<int>>l;
        for(auto p : people)
        {
           l.insert(l.begin()+p[1],p);
        }
        return l;
    }
};
