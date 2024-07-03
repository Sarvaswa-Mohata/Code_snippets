class Solution {
public:
    int func(vector<int>& nums){
        int n=nums.size();
        int prv2 = max(nums[0],0);
        int prv1 = max(nums[1],prv2);
        for(int i=2;i<n;i++){
            int pick = nums[i]+prv2;
            int not_pick = 0+prv1;
            int curr = max(pick,not_pick);
            prv2 = prv1;
            prv1 = curr;
        }
        return prv1;
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){return max(nums[0],0);}
        vector<int> v= nums;
        v.erase(v.begin());
        nums.erase(nums.begin()+n-1);
        return max(func(v),func(nums));

    }
};