class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        vector<vector<int>> dp(nums1.size(), vector<int>(nums2.size(),0));
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                int tmp=0;
                if(nums1[i]==nums2[j]){
                    dp[i][j]=1+((i>0 && j>0) ? dp[i-1][j-1] : 0);
                }
                else{
                    dp[i][j]=0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};