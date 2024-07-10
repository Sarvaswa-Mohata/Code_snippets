class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();
        if(n==0 || k>n) return 0;
        if(k<=1) return n;
        unordered_map<char,int> mp;
        for(auto it:s){
            mp[it]++;
        }
        int ind=-1, ind2=-1;
        for(int i=0;i<s.size();i++){
            auto it=s[i];
            if(mp[it]<k){
                ind =i;
            }
            while(ind!=-1 && i<n && mp[s[i]]<k){
                ind2=i;
                i++;
            }
            if(ind!=-1){
                break;
            }
        }
        if(ind!=-1){
            return max(longestSubstring(s.substr(0,ind), k), longestSubstring(s.substr(ind2+1), k));
        }
        return n;
    }
};