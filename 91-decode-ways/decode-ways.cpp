class Solution {
public:
    bool test1(int ind, string& s){
        if(ind>=s.size()){return false;}
        auto it = (s[ind]-'0');
        return (it!=0);
    }
    bool test2(int ind, string& s){
        if(ind>=s.size()-1){return false;}
        auto it=(s[ind]-'0')*10+(s[ind+1]-'0');
        return (it<=26 && it>=10);
    }
    int helper(int ind, string& s, vector<int>& dp){
        if(ind==s.size()) return 1;
        //ek char ya do char:
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=0;
        if(test1(ind, s)){
            ans+=helper(ind+1, s, dp);
        }
        if(test2(ind, s)){
            ans+=helper(ind+2, s, dp);
        }
        return dp[ind] = ans;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return helper(0,s,dp);
    }
};