class Solution {
public:

    void merge(int low, int high, vector<int>& nums){
        vector<int> v;
        int mid = (low+high)/2;
        int left = low, right = mid+1;
        while(left<=mid && right<=high){
            if(nums[left]<=nums[right]){
                v.push_back(nums[left]);
                left++;
            }
            else{
                v.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            v.push_back(nums[left]);
            left++;
        }
        while(right<=high){
            v.push_back(nums[right]);
            right++;
        }

        for(int i=low;i<=high;i++){
            nums[i]=v[i-low];
        }
    }

    void mergeSort(int low, int high, vector<int>& nums){
        //base case :
        if(low>=high){
            //single element case :
            return;
        }
        int mid = (low+high)/2;
        mergeSort(low, mid, nums);
        mergeSort(mid+1, high, nums);
        merge(low,high,nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        int low = 0;
        int high = nums.size();
        mergeSort(low, high-1, nums);
        return nums;
    }
};