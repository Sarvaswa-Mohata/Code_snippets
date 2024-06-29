class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            cnt+=mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};