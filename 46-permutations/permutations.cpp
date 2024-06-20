class Solution {
public:

    void helper(int i, vector<int>& nums, vector<vector<int>>& ans){
        int n=nums.size();
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            helper(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        helper(0,nums,ans);
        return ans;
    }
};