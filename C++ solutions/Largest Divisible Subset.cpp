class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0)
            return nums;
        int val=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>>m;
        for(auto x:nums)
        {
            m.push_back({x});
        }
        for(int i=n-1;i>=0;i--)
        {
            int index=-1;
            int s= INT_MIN;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]%nums[i]==0)
                {  
                    if(s <(int) m[j].size())
                    {
                        index=j;
                        s=m[j].size();
                        
                    }
                }               
            }
            if(index!=-1)
            {
                m[i].insert(m[i].end(),m[index].begin(),m[index].end());
                if(m[val].size()<m[i].size())
                    val=i; 
            }
        }
        return m[val];
        
    }
};
