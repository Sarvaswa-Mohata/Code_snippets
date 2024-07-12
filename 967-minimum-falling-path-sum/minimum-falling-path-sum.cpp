class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(i<0 || j<0 || j>=matrix[0].size()){
            return INT_MAX;
        }
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j]!=INT_MIN){
            return dp[i][j];
        }
        return dp[i][j] = matrix[i][j]+min({helper(i-1,j-1,matrix, dp), helper(i-1,j,matrix, dp), helper(i-1, j+1, matrix, dp)});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[n-1].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,INT_MIN));
        for(int i=0;i<m;i++){
            ans = min(ans, helper(n-1,i,matrix, dp));
        }
        return ans;
    }
};