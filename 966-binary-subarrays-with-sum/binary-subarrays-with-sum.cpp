class Solution {
public:
    int func(vector<int>& nums, int goal){
        if(goal<0){return 0;}
        int l=0, r=0, n=nums.size();
        long long int sum=0;
        int len=0, ans=0;
        while(r<n){
            sum+=nums[r];
            len++;
            while(sum>goal){
                //start shrinking
                sum-=nums[l];
                l++;
                len--;
            }
            ans+=len;
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //first find sum<=goal then subtract the no. where sum<goal
        return func(nums,goal)-func(nums,goal-1);
    }
};