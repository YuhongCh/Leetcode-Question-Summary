#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solvePuzzle(board);
    }
    
    // check if the new i element can be add into the board
    bool issafe(int row, int col, char i, const vector<vector<char>>& board){
        for (int j = 0; j < 9; j++){
            if (board[row][j] == i || board[j][col] == i) return false;
            if(board[3*(row/3) + j/3][3*(col/3) + j%3] == i) return false;
        }
        return true;
    }
    
    // backtrack algorithm
    bool solvePuzzle(vector<vector<char>>& board){
        for (int row = 0; row < 9; row++){
            for (int col = 0; col < 9; col++){
                if (board[row][col] != '.') continue;

                // try out all possible solutions
                for (char i = '1'; i <= '9'; i++){
                    if (issafe(row, col, i, board)){
                        board[row][col] = i;
                        if (solvePuzzle(board))
                            return true;
                        board[row][col] = '.';
                    }
                }
                return false;
                
            }
        }
        return true;
    }
};