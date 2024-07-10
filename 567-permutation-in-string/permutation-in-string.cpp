class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> mp,mp2;
        for(auto it:s1){
            mp2[it]++;
        }
        int l=0, r=0;
        int n=s2.size();
        int k=s1.size();
        while(r<n){
            mp[s2[r]]++;
            while(r-l+1>k){
                mp[s2[l]]--;
                if(mp[s2[l]]==0){mp.erase(s2[l]);}
                l++;
            }
            if(mp==mp2){
                return true;
            }
            r++;
        }
        return false;
    }
};