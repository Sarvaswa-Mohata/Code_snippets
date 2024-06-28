class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()), high=1e9;
        int n=weights.size();
        while(low<=high){
            long long int mid= (low+high)/2;
            int i=0;
            long long int cnt=0;
            while(i<n){
                long long int sum=0;
                while(i<n && sum+weights[i]<=mid){
                    sum+=weights[i];
                    i++;
                }
                cnt++;
            }
            if(cnt<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};