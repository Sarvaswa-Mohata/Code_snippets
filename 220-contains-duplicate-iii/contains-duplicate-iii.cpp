class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> ms;
        int l=0, r=0; 
        int n=nums.size();
        while(r<n){
            if(r-l>indexDiff){
                ms.erase(nums[l]);
                l++;
            }
            if(r>0){
                auto it = ms.lower_bound(nums[r]-valueDiff);
                if(it!=ms.end() && abs(*it-nums[r])<=valueDiff) {cout<<r<<endl;return true;}
            }
            ms.insert(nums[r]);
            r++;
        }
        return false;
    }
};