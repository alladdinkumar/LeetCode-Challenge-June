class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(coins.empty() && amount==0)
            return 1;
        else if(coins.empty() && amount>0)
            return 0;
            
        int n=amount;
        int m=coins.size();
        int a[n+1][m];
        for(int i=0;i<m;i++)
            a[0][i]=1;
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x = (i-coins[j] >= 0) ? a[i-coins[j]][j]: 0;
                int y= (j-1 >= 0) ? a[i][j-1]: 0;
                a[i][j]=x+y;
            }
        }
        return a[n][m-1];
    }
};
