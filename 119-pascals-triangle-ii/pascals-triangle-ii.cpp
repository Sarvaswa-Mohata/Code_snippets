class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> v;
        long long int ans=1;
        for(int i=1;i<=r;i++){
            v.push_back(ans);
            ans*=(r+1-i);
            ans/=i;
        }
        v.push_back(ans);
        return v;
    }
};