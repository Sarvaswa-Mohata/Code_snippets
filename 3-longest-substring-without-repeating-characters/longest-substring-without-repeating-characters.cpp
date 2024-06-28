class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, maxlen=0;
        int n=s.size();
        unordered_map<char,int> char_count;
        int ans=0;
        int tmp=0;
        while(r<n){
            char_count[s[r]]++;
            tmp++;
            while(char_count[s[r]]>1){
                tmp--;
                char_count[s[l]]--;
                l++;
            }
            ans = max(ans,tmp);
            r++;
        }
        return ans;
    }
};