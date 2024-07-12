class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // if(nums.size()==1) return false;
        auto sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){return false;}
        int n=nums.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
        sum/=2;
        dp[0][0] = true;
        dp[0][nums[0]] = true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j] =  (j>=nums[i]?dp[i-1][j-nums[i]]:false) | dp[i-1][j];
            }
        }
        return dp[n-1][sum];
    }
};