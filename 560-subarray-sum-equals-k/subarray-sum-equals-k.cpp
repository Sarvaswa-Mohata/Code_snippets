class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            mp[sum]++;
            sum+=nums[i];
            ans+=mp[sum-k];
        }
        return ans;
    }
};