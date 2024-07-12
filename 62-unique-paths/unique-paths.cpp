class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& dp){
        //base case :
        if(i<0 || j<0){
            return 0;
        }
        if(i==0 && j==0){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = helper(i-1, j, dp)+helper(i, j-1, dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return helper(n-1,m-1,dp);
    }
};