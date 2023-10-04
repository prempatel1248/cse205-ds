class Solution {
public:
    bool solve(vector<vector<char>>& board, int row, int col, char ch){
        for(int i=0; i<9; i++){
            if(board[row][i]==ch && i!=col){
                return false;
            }
            if(board[i][col]==ch && i!=row){
                return false;
            }
            if(board[(row/3)*3 + i/3][(col/3)*3 + i%3]==ch && ((row/3)*3 + i/3)!=row && ((col/3)*3 + i%3)!=col){
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row=0; row<9; row++){
            for(int col=0; col<9; col++){
                char ch = board[row][col];
                if(ch!='.' && !solve(board, row, col, ch)){
                    return false;
                }
            }
        }        
        return true;
    }
};