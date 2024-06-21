class Solution {
public:
    bool check(int i, int j, int k, vector<vector<char>>& board){
        auto temp = k+'0';
        for(int ind=0;ind<9;ind++){
            if(board[ind][j]==temp){
                return false;
            }

            if(board[i][ind]==temp){
                return false;
            }
        }
        
        int tempi = 3*(i/3), tempj = 3*(j/3);
        for(int ind=tempi;ind<tempi+3;ind++){
            for(int jnd=tempj;jnd<tempj+3;jnd++){
                if(board[ind][jnd]==temp){
                    return false;
                }
            }
        }
        return true;
    }

    bool helper(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        if(check(i,j,k,board)){
                            board[i][j]='0'+k;
                            if(helper(board)){
                                return true;
                            }
                            else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
};