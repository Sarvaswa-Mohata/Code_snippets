class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0, ans=0, tmp=0;
        int n=s.size();
        map<char,int> mp;
        while(r<n){
            mp[s[r]]++;
            while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
                //start shrinking
                mp[s[l]]--;
                l++;
            }
            ans+=l;
            r++;
        }
        return ans;
    }
};