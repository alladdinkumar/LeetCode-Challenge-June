class Solution {
public:
    vector<int>sol;
    Solution(vector<int>& w) {
        sol=vector<int>(w.size());
        int sum=0;
        for(int i=0;i<w.size();i++)
        {
            sum+=w[i];
            sol[i]=sum;
        }
    }
    
    int pickIndex() {
        int n=sol.size()-1;
        int num=rand()%sol[n];
        int l=0,r=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(sol[mid]<=num)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
