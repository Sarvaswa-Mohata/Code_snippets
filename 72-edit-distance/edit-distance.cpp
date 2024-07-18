class Solution {
public:
    int helper(int ind1, int ind2, string& w1, string& w2, int n, int m, vector<vector<int>>& dp){
        if(ind1>n || ind2>m){return 1e8;}
        if(ind1==n && ind2==m){return 0;}
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(ind1<n && ind2<m && w1[ind1]==w2[ind2]){
            return dp[ind1][ind2] = helper(ind1+1, ind2+1, w1, w2, n, m, dp);
        }
        return dp[ind1][ind2] = min({1+helper(ind1, ind2+1, w1, w2, n, m, dp), 1+helper(ind1+1, ind2, w1, w2, n, m, dp), 1+helper(ind1+1, ind2+1, w1, w2, n, m, dp)});
    }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return helper(0, 0, w1, w2, n, m, dp);
    }
};