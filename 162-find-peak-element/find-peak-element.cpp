class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //edge cases:
        int n=nums.size();
        if(nums.size()==1 || nums[0]>nums[1]){
            return 0;
        }
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        //trim down the search space:
        int low=1, high=n-2;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(nums[mid]<nums[mid+1]){
                //part of increasing curve:
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};