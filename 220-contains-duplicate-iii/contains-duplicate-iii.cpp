class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> mySet;
        for(int i = 0; i<nums.size(); i++){
        	auto lb = mySet.lower_bound(nums[i]-t);
        	//lower_bound returns the iterator (the most near to value equals to nums[i] - t) , this is tricky
        	if(lb!=mySet.end() && *lb - nums[i]<=t) return true;
        	mySet.insert(nums[i]);
        	if(mySet.size()>k) mySet.erase(nums[i-k]);

        }
    return false;
    }
};