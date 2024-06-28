class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        long long int low=1;
        long long int high = 1e9;
        int n=nums.size();
        while(low<=high){
            long long int mid = (low+high)/2;
            long long int ans=0;
            for(int i=0;i<n;i++){
                ans +=ceil((double)nums[i]/mid);
            }
            if(ans<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};