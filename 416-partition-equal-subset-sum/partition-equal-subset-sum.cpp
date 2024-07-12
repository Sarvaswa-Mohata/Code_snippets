class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // if(nums.size()==1) return false;
        auto sum= accumulate(nums.begin(),nums.end(),0);
        if(sum%2==1){return false;}
        int n=nums.size();
        vector<bool> prev(sum+1, false);
        sum/=2;
        prev[0] = true;
        prev[nums[0]] = true;
        for(int i=1;i<n;i++){
            vector<bool> curr(sum+1,false);
            for(int j=0;j<=sum;j++){
                curr[j] =  (j>=nums[i]?prev[j-nums[i]]:false) | prev[j];
            }
            prev = curr;
        }
        return prev[sum];
    }
};