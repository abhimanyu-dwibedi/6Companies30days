class Solution {
  public:
    int maxProfit(int k, int n, int A[]) {
        // code here\
        
          int dp[k+1][n];
             int max_so=INT_MIN;
       for(int i=1;i<=k;i++)
       {
           max_so=INT_MIN;
           for(int j=1;j<n;j++)
           {
               max_so=max(max_so,dp[i-1][j-1]-A[j-1]);
               dp[i][j]=max(dp[i][j-1],max_so+A[j]);
           }
       }
       return dp[k][n-1];
    }
};
