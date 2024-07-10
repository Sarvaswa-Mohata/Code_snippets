class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int l=0, r=0;
        int n=s.size();
        map<string,int> mp;
        while(r<n){
            //s.substr(l,r-l+1);
            while(r-l+1>10){
                l++;
            }
            if(r-l+1==10){
                auto tmp= s.substr(l,r-l+1);
                mp[tmp]++;
            }
            r++;
        }
        vector<string> v;
        for(auto it:mp){
            if(it.second>1){
                v.push_back(it.first);
            }
        }
        return v;
    }
};