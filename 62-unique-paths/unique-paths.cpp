class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(m,0);
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                if(i==0 && j==0) {curr[j] = 1; continue;}
                curr[j] = (i>0 ? prev[j] : 0) + (j>0 ? curr[j-1] : 0);
            }
            prev = curr;
        }
        return prev[m-1];
    }
};