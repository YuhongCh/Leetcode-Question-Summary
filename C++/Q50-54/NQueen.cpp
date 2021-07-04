#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValid(vector<string>& board, int row, int col){
        int n = row;
        for (int i = 1; i <= n; i++){
            row--;
            if (board[row][col] == 'Q') return false;
            if (col + i < board.size() && board[row][col+i] == 'Q') return false;
            if (col - i >= 0 && board[row][col-i] == 'Q') return false;
        }
        return true;
    }
    
    void backtrack(vector<vector<string>>& result, vector<string>& board, int row){
        if (row == board.size()){
            result.push_back(board);
            return;
        }
        for (int col = 0; col < (int)board.size(); col++){
            if (checkValid(board, row, col)){
                board[row][col] = 'Q';
                backtrack(result, board, row+1);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string>board(n, string(n, '.'));
        backtrack(result, board, 0);
        return result;
    }
};