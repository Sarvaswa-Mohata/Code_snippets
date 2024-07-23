class Solution {
public:
    long long int C(int n, int r){
        if(n<r) return 0;
        r = min(r, n-r);
        long long int ans=1;
        for(int i=n;i>r;i--){
            ans*=i;
            ans/=(n-i+1);
        }
        return ans;
    }
    long long int numTrees(int n) {
        long long int ans = C(2*n,n)/(n+1);
        return ans;
    }
};