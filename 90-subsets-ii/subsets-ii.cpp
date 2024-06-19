class Solution {
public:

    void helper(int i, vector<int>& container, map<int,int>& mp, vector<vector<int>>& ans, vector<int>& v){ 
        //base case :
        if(i==container.size()){
            ans.push_back(v);
            return;
        }

        //pick:
        if(mp[container[i]]>0){
            v.push_back(container[i]);
            mp[container[i]]--;
            helper(i, container, mp, ans, v);
            mp[container[i]]++;
            v.pop_back();
        }

        //leave:
        helper(i+1, container, mp, ans, v);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> container;
        map<int,int> mp;
        vector<vector<int>> ans;
        vector<int> v;
        for(auto it:nums){
            mp[it]++;
        }
        for(auto it:mp){
            container.push_back(it.first);
        }
        helper(0, container, mp, ans, v);
        return ans;
    }
};