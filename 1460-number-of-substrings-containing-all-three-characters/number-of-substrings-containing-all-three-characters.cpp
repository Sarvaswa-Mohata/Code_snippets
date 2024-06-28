class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0, ans=0, tmp=0;
        int n=s.size();
        vector<int> mp(3,0);
        while(r<n){
            mp[s[r]-'a']++;
            while(mp[0]>=1 && mp[1]>=1 && mp[2]>=1){
                //start shrinking
                mp[s[l]-'a']--;
                l++;
            }
            ans+=l;
            r++;
        }
        return ans;
    }
};