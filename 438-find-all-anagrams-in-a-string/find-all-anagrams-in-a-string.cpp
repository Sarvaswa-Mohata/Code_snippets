class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l=0, r=0;
        unordered_map<char,int> mp;
        int n=s.size();
        int k=p.size();
        unordered_map<char,int> mp2;
        for(auto it:p){
            mp2[it]++;
        }
        vector<int> v;
        while(r<n){
            mp[s[r]]++;
            while(r-l+1>k){
                mp[s[l]]--;
                if(mp[s[l]]==0){mp.erase(s[l]);}
                l++;
            }
            if(mp==mp2){
                v.push_back(l);
            }
            r++;
            cout<<endl;
        }
        return v;
    }
};