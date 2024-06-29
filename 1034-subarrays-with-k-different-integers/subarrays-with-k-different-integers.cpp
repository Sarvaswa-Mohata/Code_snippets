class Solution {
public:
    int func(vector<int>& nums, int k){
        int l=0, r=0, n=nums.size(), ans=0, sum=0;
        int len=0;
        unordered_map<int,int> mp;
        while(r<n){
            mp[nums[r]]++;
            len++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
                len--;
            }
            ans+=len;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums,k)-func(nums,k-1);
    }
};