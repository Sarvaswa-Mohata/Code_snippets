class Solution {
public:
    int func(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i<0){
            return (target==1000);
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        return dp[i][target] = (target>=nums[i] ? func(i-1, target-nums[i], nums, dp) : 0) +(target+nums[i]<=2000 ? func(i-1, target+nums[i], nums, dp) : 0);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        target=1000+target;
        vector<vector<int>> dp(n, vector<int>(2001, -1));
        return func(n-1, target, nums, dp);
    }
};