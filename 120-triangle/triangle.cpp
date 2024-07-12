class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        int ans = INT_MAX;
        vector<int> prev(m,INT_MAX);
        if(n==1){
            return triangle[0][0];
        }
        for(int i=0;i<n;i++){
            vector<int> curr(m,INT_MAX);
            for(int j=0;j<m;j++){
                if(j>i) continue;
                if(i==0 && j==0){curr[j] = triangle[i][j]; continue;}
                curr[j] = triangle[i][j]+min((i>0 ? prev[j] : INT_MAX), (i>0 && j>0 ? prev[j-1] : INT_MAX));
            }
            prev = curr;
        }
        for(auto it:prev){
            cout<<it<<" ";
            ans = min(ans,it);
        }
        return ans;
    }
};