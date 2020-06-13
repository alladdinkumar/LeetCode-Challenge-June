class Solution {
public:
    
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n<2)
            return;           
        int cnt1=0,cnt2=n-1;
        for(int i=0;i<=cnt2;i++)
        {
            if(nums[i]==0)
            {
                if(i==cnt1)
                    continue;
                int temp=nums[i];
                nums[i]=nums[cnt1];
                nums[cnt1]=temp;
                cnt1++;
                i--;
            }
            else if(nums[i]==2 )
            {
                int temp=nums[i];
                nums[i]=nums[cnt2];
                nums[cnt2]=temp;
                cnt2--;
                i--;
            }
        }
        
    }
};
