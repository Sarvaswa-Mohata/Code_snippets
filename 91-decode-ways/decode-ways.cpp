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
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n+1, 0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int ans=0;
            if(test1(i, s)){
                ans+=dp[i+1];
            }
            if(test2(i, s)){
                ans+=dp[i+2];
            }
            dp[i] = ans;
        }
        return dp[0];
    }
};