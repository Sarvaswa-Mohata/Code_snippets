class Solution {
public:
    long long solve(vector<int>& nums, int target){
        map<long long,long long> mp;
        long long sum=0;
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            mp[sum]++;
            sum^=nums[i];
            cnt+=mp[sum^target];
        }
        mp[sum]++;
        return cnt;
    } 

    long long beautifulSubarrays(vector<int>& nums) {
        return solve(nums,0);
    }
};