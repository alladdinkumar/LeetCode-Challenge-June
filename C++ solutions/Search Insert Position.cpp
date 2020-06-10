class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int mid= (l+r)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
        
    }
};