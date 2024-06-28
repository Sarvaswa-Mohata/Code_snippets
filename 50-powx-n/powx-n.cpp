class Solution {
public:
    void solve(double x, long long int n, double& ans) {
        if (n <= 0) {
            cout<<"hi";
            return;
        }
        int tmp = log2(n);
        double cpy = x;
        for (int i = 0; i < tmp; i++) {
            cpy *= cpy;  // Compute x^(2^i)
        }
        long long int tmpo=1;
        for(int i=0;i<tmp;i++){
            tmpo*=2;
        }
        n -= tmpo;  // Reduce n by 2^tmp
        // cout<<ans;
        ans *= cpy;  // Multiply the result into ans
        solve(x, n, ans);  // Recursively solve the remaining part of n
    }


    double myPow(double x, int n) {
        long long n_ = n;
        if(n_<0){n_ = -n_;}
        double ans=1;
        solve(x,n_,ans);
        if(n<0){
            ans = 1/ans;
        }
        return ans;
    }
};