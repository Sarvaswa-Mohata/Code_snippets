class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[n-1].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,INT_MIN));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0)
                dp[i][j]=matrix[i][j];
                else
                dp[i][j] = matrix[i][j]+min({j>0 ? dp[i-1][j-1] : INT_MAX, dp[i-1][j], j<m-1 ? dp[i-1][j+1] : INT_MAX});
                if(i==n-1){
                    ans = min(ans,dp[i][j]);
                }
            }
        }
        return ans;
    }
};