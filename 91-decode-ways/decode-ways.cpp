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
        int n = s.size();
        if (n == 0) {
            return 0;
        }

        // Initializing the variables
        int nxt1 = 1;  // This represents dp[i+1] which is initially dp[n]
        int nxt2 = 0;  // This represents dp[i+2]
        int curr = 0;

        // Loop from the end of the string towards the beginning
        for (int i = n - 1; i >= 0; i--) {
            curr = 0;
            if (test1(i, s)) {
                curr += nxt1;
            }
            if (test2(i, s)) {
                curr += nxt2;
            }
            nxt2 = nxt1;
            nxt1 = curr;
        }
        return nxt1;
    }
};