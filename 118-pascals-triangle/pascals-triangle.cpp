class Solution {
public:
    vector<vector<int>> generate(int num) {
        vector<vector<int>> v;
        for(int i=1;i<=num;i++){
            vector<int> tmp;
            int ans=1;
            for(int j=0;j<i;j++){
                if(j!=0){
                    ans*=(i-j);
                    ans/=j;
                }
                tmp.push_back(ans);
            }
            v.push_back(tmp);
        }
        return v;
    }
};