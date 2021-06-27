#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:  
    int box_decider( int row, int col ){
        if( row < 3 ){
            if( col < 3 ) return 0;
            if( col < 6 ) return 1;
            return 2;
        }
        else if( row < 6 ){
            if( col < 3 ) return 3;
            if( col < 6 ) return 4;
            return 5;
        }
        else{
            if( col < 3 ) return 6;
            if( col < 6 ) return 7;
            return 8;
        }
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>>row(9,vector<int>(9, -1));
        vector<vector<int>>col(9,vector<int>(9, -1));
        vector<vector<int>>box(9,vector<int>(9, -1));
        
        for( int r = 0; r < 9; r++ ){
            for( int c = 0; c < 9; c++ ){
                if( board[r][c] == '.' ){
                    continue;
                }
                int res = board[r][c]-'0';
                if( col[c][res-1] == -1 ){
                    col[c][res-1] = res;
                }
                else{
                    return false;
                }
                if( row[r][res-1] == -1 ){
                    row[r][res-1] = res;
                }
                else{
                    return false;
                }
                int b = box_decider(r,c);
                if( box[b][res-1] == -1 ){
                    box[b][res-1] = res;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};


// a pretty solution, but is quite time consuming
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,int>hash;
        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){
                if(board[row][col] != '.')
                {
    
                    string r= "row"+to_string(row)+to_string(board[row][col]);
                    string c= "col"+to_string(col)+to_string(board[row][col]);
                    int b = (row/3) * 3 + (col/3);
                    string box= "box"+ to_string(b) + to_string(board[row][col]);

                    if(hash[r] != 1 && hash[c] != 1 && hash[box] != 1){
                        hash[r]=1;
                        hash[c]=1;
                        hash[box]=1;
                    }else{
                        return false;
                    }

                    }
                
            }
        }
        
        return true;
    }
};