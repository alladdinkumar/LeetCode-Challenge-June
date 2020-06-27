class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int>bits(32,0);
        for(auto x:nums)
        {
            for(int i=0;i<32;i++)
                if((1<<i) & x)
                    bits[i]= (bits[i]+1)%3;
            
        }
       int ans=0;
        for(int i=0;i<32;i++)
                if(bits[i]==1)
                    ans+=(1<<i);
        return ans;
    }
};
