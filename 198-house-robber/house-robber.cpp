class Solution {
public:
    int func(vector<int>& nums){
        int n=nums.size();
        vector<int> dp(n,-1);
        dp[0] = max(nums[0],0);
        if(n>1)
        dp[1] = max(nums[1],dp[0]);
        for(int i=2;i<n;i++){
            int pick = nums[i]+dp[i-2];
            int not_pick = 0+dp[i-1];
            dp[i] = max(pick,not_pick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        return func(nums);
    }
};