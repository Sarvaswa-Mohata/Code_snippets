class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int left=0, right=m-1, top=0, bottom=n-1;
        vector<int> v;
        while(top<=bottom && left<=right){
            //right
            for(int i=left;i<=right;i++){
                v.push_back(matrix[top][i]);
            }
            top++;

            //bottom
            for(int i=top;i<=bottom;i++){
                v.push_back(matrix[i][right]);
            }
            right--;

            //left
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            
            //top
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return v;
    }
};