class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m=d.size();
        int n=d[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]= d[m-1][n-1] > 0? 1: 1-d[m-1][n-1];
        for(int i=m-2;i>=0;i--)
            dp[i][n-1]= max(dp[i+1][n-1]-d[i][n-1],1);
        for(int j=n-2;j>=0;j--)
            dp[m-1][j]= max(dp[m-1][j+1]-d[m-1][j],1);
        
         for(int i=m-2;i>=0;i--){
             for(int j=n-2;j>=0;j--){
                 dp[i][j]= max(min(dp[i+1][j],dp[i][j+1])-d[i][j],1);
             }
         }
        return dp[0][0];
    }
};
