class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //Transpose and then reverse the contents of every row
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        //now just reverse:
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};