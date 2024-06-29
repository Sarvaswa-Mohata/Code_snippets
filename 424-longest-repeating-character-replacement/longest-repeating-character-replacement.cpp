class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> v(26,0);
        int l=0, r=0;
        int ans=0;
        int tmp=0;
        int maxfreq=0;
        int n=s.size();
        while(r<n){
            v[s[r]-'A']++;
            tmp++;
            if(v[s[r]-'A']>maxfreq){
                maxfreq = v[s[r]-'A'];
            }
            while(tmp-maxfreq>k){
                v[s[l]-'A']--;
                //update maxfreq
                maxfreq = *max_element(v.begin(),v.end());
                //update len
                tmp--;
                l++;
            }
            ans = max(ans,tmp);
            r++;
        }
        return ans;
    }
};