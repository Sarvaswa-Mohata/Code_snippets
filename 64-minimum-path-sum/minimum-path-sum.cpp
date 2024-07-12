class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        return dp[i][j] = grid[i][j]+min(helper(i-1, j, grid, dp),helper(i,j-1, grid, dp));
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){ dp[i][j] = grid[i][j]; continue;}
                dp[i][j] = grid[i][j]+min((i>0 ? dp[i-1][j] : INT_MAX),(j>0 ? dp[i][j-1] : INT_MAX));
            }
        }
        return dp[m-1][n-1];
    }
};