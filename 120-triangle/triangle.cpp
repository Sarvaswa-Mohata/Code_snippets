class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i<0 || j<0 || j>i){
            return INT_MAX;
        }
        if(i==0 && j==0){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j] = triangle[i][j]+min(helper(i-1, j, triangle, dp), helper(i-1, j-1, triangle, dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m,-1));
        for(int i=0;i<m;i++){
            auto tmp = helper(n-1, i, triangle, dp);
            ans = min(ans, tmp);
        }
        return ans;
    }
};