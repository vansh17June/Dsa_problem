class Solution {
public:
    bool valid(vector<vector<char>>& board,int i,int j,char ch){
        for(int k=0;k<9;k++){
            if(board[i][k]==ch||board[k][j]==ch){
                return false;
            }
        }
        int row=(i/3)*3,col=(j/3)*3;
        for(int k=row;k<row+3;k++){
            for(int l=col;l<col+3;l++){
                if(board[k][l]==ch){
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int k=1;k<=9;k++){
                        char t=k+'0';
                        if(valid(board,i,j,t)){
                            board[i][j]=t;
                            if(solve(board)){
                                return true;
                            }
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
       solve(board);
    }
};