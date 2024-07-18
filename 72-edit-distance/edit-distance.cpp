class Solution {
public:
    int helper(int ind1, int ind2, string& w1, string& w2, vector<vector<int>>& dp){
        if(ind1<0) return ind2+1;
        if(ind2<0) return ind1+1;
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(w1[ind1]==w2[ind2]){
            return dp[ind1][ind2] = helper(ind1-1, ind2-1, w1, w2, dp);
        }
        return dp[ind1][ind2] = min({1+helper(ind1, ind2-1, w1, w2, dp), 1+helper(ind1-1, ind2, w1, w2, dp), 1+helper(ind1-1, ind2-1, w1, w2, dp)});
    }
    int minDistance(string w1, string w2) {
        int n=w1.size();
        int m=w2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return helper(n-1, m-1, w1, w2, dp);
    }
};