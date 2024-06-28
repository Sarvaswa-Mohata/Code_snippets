class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        long long int n= piles.size();
        long long int low=1, high=piles[n-1];
        int ans=0;
        while(low<=high){
            long long int mid = low+(high-low)/2;
            //assuming mid is the ans:
            long long int tmp=0;
            for(int i=0;i<piles.size();i++){
                tmp+=ceil((double)piles[i]/mid);
            }
            if(tmp<=h){
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