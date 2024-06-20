class Solution {
public:

    void helper(vector<bool>& vis, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums){
        if(v.size()==nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                v.push_back(nums[i]);
                vis[i]=true;
                helper(vis, v, ans, nums);
                vis[i]=false;
                v.pop_back();
            }
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> v;
        vector<bool> vis(n,false);
        helper(vis, v, ans, nums);
        return ans;
    }
};