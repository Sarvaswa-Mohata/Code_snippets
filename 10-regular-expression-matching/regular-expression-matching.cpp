class Solution {
public:
    bool helper(int ind1, int ind2, string& s, string& p, int n, int m, vector<vector<int>>& dp){
        if(ind1>=n){
            for(int i=ind2;i<m;i++){
                if(p[i]=='*' || p[i+1]=='*') continue;
                return false;
            }
            return true;
        }
        if(ind2>=m){
            if(ind1>=n) return true;
            return false;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(p[ind2]!='.' && p[ind2]!='*'){
            if(s[ind1]!=p[ind2] && (ind2+1==m || p[ind2+1]!='*')){
                return dp[ind1][ind2]=0;
            }
            if(p[ind2+1]=='*')
            return dp[ind1][ind2]=helper(ind1, ind2+1, s, p, n, m, dp);
            return dp[ind1][ind2]=helper(ind1+1, ind2+1, s, p, n, m, dp);
        }
        if(p[ind2]=='.'){
            if(ind2+1<m && p[ind2+1]=='*'){
                return dp[ind1][ind2]=helper(ind1, ind2+1, s, p, n, m, dp);
            }
            return dp[ind1][ind2]=helper(ind1+1, ind2+1, s, p, n, m, dp);
        }
        if(p[ind2]=='*'){
            bool ans = false;
            ans|= helper(ind1, ind2+1, s, p, n, m, dp); //matching 0 chars
            if(p[ind2-1]=='.'){
                while(ind1<n){
                    ans|=helper(ind1+1, ind2+1, s, p, n, m, dp);
                    ind1++;
                }
            }
            else{
                auto it = p[ind2-1];
                while(ind1<n && s[ind1]==it){
                    ans|=helper(ind1+1, ind2+1, s, p, n, m, dp); //matching 1 or more chars
                    ind1++;
                }
            }
            return dp[ind1][ind2] = ans;
        }
        return true;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size()+1, vector<int>(p.size()+1, -1));
        return helper(0,0,s,p,s.size(),p.size(),dp);
    }
};