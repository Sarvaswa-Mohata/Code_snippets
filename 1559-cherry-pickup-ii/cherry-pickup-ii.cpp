class Solution {
public:
    int func(int i, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        int n=grid.size();
        int m=grid[0].size();
        if(c1<0 || c1>=m || c2<0 || c2>=m){
            return -1e8;
        }
        if(i==n-1){
            if(c1==c2){
                return grid[i][c1];
            }
            return grid[i][c1]+grid[i][c2];
        }
        if(dp[i][c1][c2]!=-1){
            return dp[i][c1][c2];
        }
        int ans=INT_MIN;
        for(int indi=c1-1;indi<=c1+1;indi++){
            for(int indj=c2-1;indj<=c2+1;indj++){
                if(indi!=indj)
                ans = max(ans, grid[i][c1] + grid[i][c2] + func(i+1,indi,indj,grid,dp));
            }
        }
        return dp[i][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(), -1)));
        return func(0,0,grid[0].size()-1,grid,dp);
    }
};