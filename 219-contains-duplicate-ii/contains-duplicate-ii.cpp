class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l=0, r=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            while(r-l>k){
                mp[nums[l]]--;
                l++;
            }
            if(mp[nums[r]]>1){return true;}
            r++;
        }
        return false;
    }
};