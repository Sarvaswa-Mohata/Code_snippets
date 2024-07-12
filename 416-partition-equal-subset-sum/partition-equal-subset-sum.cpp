class Solution {
public:
    bool helper(int i, int sum, vector<int>& nums, vector<vector<int>>& dp){
        if(sum<0){
            return false;
        }
        if(i<0){
            return sum==0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        return dp[i][sum] = helper(i-1, sum-nums[i], nums,dp) | helper(i-1, sum, nums, dp);
    }
    bool canPartition(vector<int>& nums) {
        auto sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){return false;}
        sum/=2;
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return helper(n-1, sum, nums, dp);
    }
};