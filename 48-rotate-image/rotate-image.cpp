class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> cpy = matrix;
        int n=matrix.size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                cpy[j][n-1-i] = matrix[i][j];
            }
        }
        matrix=cpy;
    }
};