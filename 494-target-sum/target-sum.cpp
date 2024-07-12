class Solution {
public:
    int func(int i, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(i<0){
            return (target==2000);
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        return dp[i][target] = func(i-1, target-nums[i], nums, dp) + func(i-1, target+nums[i], nums, dp);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        target=2000+target;
        vector<vector<int>> dp(n, vector<int>(10000, -1));
        return func(n-1, target, nums, dp);
    }
};