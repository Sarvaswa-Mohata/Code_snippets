class Solution {
public:
    bool helper(int i, int j, string& s, string& p, int n, int m, vector<vector<int>>& dp){
        if(j>=m) return (i>=n ? true : false);
        if(i>=n){
            for(int k=j;k<m;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(p[j]!='*' && p[j]!='?'){
            if(p[j]==s[i])
            return dp[i][j] = helper(i+1, j+1, s, p, n, m, dp);
            return dp[i][j] = false;
        }
        else if(p[j]=='?'){
            return dp[i][j] = helper(i+1, j+1, s, p, n, m, dp);
        }
        else{
            bool ans = false;
            for(int k=i;k<=n;k++){
                ans|=helper(k, j+1, s, p, n, m, dp);
            }
            return dp[i][j] = ans;
        }
        return false;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(0,0,s,p,s.size(),p.size(),dp);   
    }
};