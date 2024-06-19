class Solution {
public:

    void recursive(int i, vector<int>& nums, vector<int>& v, vector<vector<int>>& ans){
        //base case :
        if(i==nums.size()){
            ans.push_back(v);
            return;
        }
        //pick
        v.push_back(nums[i]);
        recursive(i+1, nums, v, ans);
        v.pop_back();
        
        //leave
        recursive(i+1, nums, v, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        //for every element we need to take a decision either to take it or to leave it
        vector<int> v;
        vector<vector<int>> ans;
        recursive(0, nums, v, ans); 
        return ans;
    }
};