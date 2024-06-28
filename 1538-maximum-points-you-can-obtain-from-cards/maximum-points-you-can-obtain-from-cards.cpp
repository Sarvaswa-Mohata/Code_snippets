class Solution {
public:
    int maxScore(vector<int>& v, int k) {
        int lsum=0, rsum=0;
        int l=0, r=0;
        int sum=0;
        int n=v.size();
        int rind=n-1;
        lsum = accumulate(v.begin(),v.begin()+k,0);
        int ans = lsum;
        for(int i=k-1;i>=0;i--){
            lsum-=v[i];
            rsum+=v[rind];
            rind-=1;
            ans = max(ans, lsum+rsum);
        }
        return ans;
    }
};