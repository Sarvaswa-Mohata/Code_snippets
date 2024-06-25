class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            //you always have 2 options either to continue with existing sum and add the new element or take the new element separately:
            sum=max(sum+nums[i], nums[i]);
            ans = max(ans,sum);
        }
        return ans;
    }
};