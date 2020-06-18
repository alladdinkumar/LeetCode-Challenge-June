class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        if(n<1)
            return 0;
        int l=0;
        int r=n-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;                
            if(citations[mid]>=n-mid)
            {
                ans=mid;
                r=mid-1;
            }  
            else
               l=mid+1 ;
            
        }
        return ans==-1?0:n-ans;
    }
};
