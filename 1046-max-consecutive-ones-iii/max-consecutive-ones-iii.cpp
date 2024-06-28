class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0,cnt=0;
        int ans=0, n=nums.size();
        while(r<n){
            if(nums[r]==0 && k>=0){
                k--;
            }
            cnt++;
            //shrink kab krna hai:
            while(nums[r]==0 && k==-1){
                if(nums[l]==0){k++;}
                l++;
                cnt--;
            }
            ans = max(ans,cnt);
            r++;
        }
        return ans;
    }
};