class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        long long int low=*min_element(nums.begin(),nums.end());
        long long int high=*max_element(nums.begin(),nums.end());
        long long int n=nums.size();
        int ans=-1;
        while(low<=high){
            long long int mid = low+(high-low)/2;
            //assume mid is the ans:
            long long int cnt =0;
            for(int i=0;i<n;){
                int j=0;
                while(i+j<n && j<k && nums[i+j]<=mid){
                    j++;
                }
                if(j==k){
                    cnt++;
                }
                i+=max(j,1);
            }
            if(cnt>=m){
                ans = mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};