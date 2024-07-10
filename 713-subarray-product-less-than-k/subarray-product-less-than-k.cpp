class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0, r=0;
        int n=nums.size();
        long long int prod=1;
        int ans=0;
        if(k<=1){
            return 0;
        }
        while(r<n){
            prod*=nums[r];
            while(l<n && prod>=k){
                prod=prod/nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return max(ans,0);
    }
};