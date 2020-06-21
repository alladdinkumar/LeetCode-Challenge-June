class Solution {
    vector<vector<int>>ans;
    int size;
public:
    void recur(vector<int>not_visi,vector<int>num,int turn)
    {
        if(turn==size)
            ans.push_back(num);
        else
        {
            for(auto x=not_visi.begin();x!=not_visi.end();x++)
            {
                int val=*x;
                num.push_back(val);
                not_visi.erase(x);
                recur(not_visi,num,turn+1);
                num.erase(num.end()-1);
                not_visi.insert(x,val);
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty())
            return ans;
        size=nums.size();
        vector<int>not_visi=nums;
        vector<int>num;
        recur(not_visi,num,0);
        return ans;
        
    }
};
