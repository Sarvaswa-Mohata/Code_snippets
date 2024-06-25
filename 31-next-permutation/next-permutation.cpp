class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                ind = i;
            }
        }
        if(ind==-1){
            sort(nums.begin(),nums.end());
        }
        else{
            sort(nums.begin()+ind+1,nums.end());
            auto it = upper_bound(nums.begin()+ind+1,nums.end(),nums[ind])-nums.begin();
            swap(nums[ind],nums[it]);
            sort(nums.begin()+it,nums.end());
        }
    }
};