class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2,0);
        int n=grid.size();
        vector<int> gd(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                gd[grid[i][j]]++;
            }
        }
        for(int i=1;i<gd.size();i++){
            if(gd[i]==2){
                ans[0]=i;
            }
            if(gd[i]==0){
                ans[1]=i;
            }
        }
        return ans;
    }
};