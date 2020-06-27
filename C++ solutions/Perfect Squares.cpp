class Solution {
    int count;
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        int j,min,sq;
        for(int i=1;i<=n;i++)
        {
            min=i;
            j=1,sq=1;
            while(sq<=i)
            {
                min= min < 1+dp[i-sq]?min:1+dp[i-sq];
                j++;
                sq=j*j;
            }
            dp[i]=min;
        }
        return dp[n];
    }
};
