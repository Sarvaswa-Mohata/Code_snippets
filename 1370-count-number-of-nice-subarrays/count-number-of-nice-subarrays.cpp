class Solution {
public:
    int func(vector<int>& nums, int k){
        int l=0, r=0, ans=0, sum=0, len=0;
        int n=nums.size();
        while(r<n){
            len++;
            sum+=nums[r];
            while(sum>k){
                sum-=nums[l];
                l++;
                len--;
            }
            ans+=len;
            r++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            nums[i]%=2;
        }
        //now the nums is a binary array where the sum must be k:
        return func(nums,k)-func(nums,k-1);
    }
};