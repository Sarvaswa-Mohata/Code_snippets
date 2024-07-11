class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans=1;
        if(arr.size()==1){return ans;}
        int l=0, r=0;
        int n=arr.size();
        while(r<n){
            if(r<2){
                if(r!=0){
                    if(arr[r]==arr[r-1])
                    l=r;
                    else
                    ans = max(ans,2);
                }
                r++;
                continue;
            }
            if(arr[r]==arr[r-1]){
                l=r;
            }
            else if(arr[r-1] == arr[r-2] || (arr[r]-arr[r-1])/abs(arr[r]-arr[r-1]) == (arr[r-1]-arr[r-2])/abs(arr[r-1]-arr[r-2])){
                l=r-1;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};