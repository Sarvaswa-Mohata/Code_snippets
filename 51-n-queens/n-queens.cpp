class Solution {
public:

   bool check(int i, int j, vector<string>& v) {
        int n = v.size();
        // Check the column
        for (int ind = 0; ind < n; ind++) {
            if (v[ind][j] == 'Q') {
                return false;
            }
        }
        // Check the row
        for (int jnd = 0; jnd < n; jnd++) {
            if (v[i][jnd] == 'Q') {
                return false;
            }
        }
        // Check the diagonals
        int tmpi, tmpj;
        
        // Back and up diagonal
        tmpi = i;
        tmpj = j;
        while (tmpi >= 0 && tmpj >= 0) {
            if (v[tmpi][tmpj] == 'Q') {
                return false;
            }
            tmpi--;
            tmpj--;
        }
        
        // Back and down diagonal
        tmpi = i;
        tmpj = j;
        while (tmpi < n && tmpj >= 0) {
            if (v[tmpi][tmpj] == 'Q') {
                return false;
            }
            tmpi++;
            tmpj--;
        }
        
        // Forward and up diagonal
        tmpi = i;
        tmpj = j;
        while (tmpi >= 0 && tmpj < n) {
            if (v[tmpi][tmpj] == 'Q') {
                return false;
            }
            tmpi--;
            tmpj++;
        }
        
        // Forward and down diagonal
        tmpi = i;
        tmpj = j;
        while (tmpi < n && tmpj < n) {
            if (v[tmpi][tmpj] == 'Q') {
                return false;
            }
            tmpi++;
            tmpj++;
        }
        
        return true;
    }

    void recursive(int i, int n, vector<string>& v, vector<vector<string>>& ans){
        if(i==n){
            ans.push_back(v);
            return;
        }
        
        for(int j=0;j<n;j++){
            if(v[i][j]=='.' && check(i,j,v)){
                v[i][j]='Q';
                recursive(i+1, n, v, ans);
                v[i][j]='.';
            }
        }
        return;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s(n,'.');
        vector<string> v;
        for(int i=0;i<n;i++){
            v.push_back(s);
        }
        recursive(0,n,v,ans);
        return ans;
    }
};