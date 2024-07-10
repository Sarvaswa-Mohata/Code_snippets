class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int low=0, high=n-k-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        vector<int> v;
        for(int i=low;i<low+k;i++){
            v.push_back(arr[i]);
        }
        return v;
    }
};