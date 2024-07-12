class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[n-1].size();
        int ans = INT_MAX;
        vector<int> prev(m,INT_MIN);
        for(int i=0;i<n;i++){
            vector<int> curr(m,INT_MIN);
            for(int j=0;j<m;j++){
                if(i==0)
                curr[j]=matrix[i][j];
                else
                curr[j] = matrix[i][j]+min({j>0 ? prev[j-1] : INT_MAX, prev[j], j<m-1 ? prev[j+1] : INT_MAX});
            }
            prev = curr;
        }
        for(auto it:prev){
            ans = min(ans, it);
        }
        return ans;
    }
};