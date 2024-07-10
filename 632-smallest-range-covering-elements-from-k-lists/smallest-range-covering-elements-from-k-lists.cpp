class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[i].size();j++){
                v.push_back({nums[i][j], i});
            }
        }
        sort(v.begin(),v.end());
        int k=nums.size();
        unordered_map<int,int> mp;
        int l=0, r=0, n=v.size();
        int ans = INT_MAX;
        vector<int> tmp = {v[0].first,v[v.size()-1].first};
        while(r<n){
            mp[v[r].second]++;
            while(mp.size()==k){
                if(v[r].first-v[l].first<ans){
                    ans = v[r].first-v[l].first;
                    tmp = {v[r].first,v[l].first};
                }
                ans = min(ans, v[r].first-v[l].first);
                mp[v[l].second]--;
                if(mp[v[l].second]==0){
                    mp.erase(v[l].second);
                }
                l++;
            }
            r++;
        }
        return tmp;
    }
};