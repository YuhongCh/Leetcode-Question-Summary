#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void transpose(vector<vector<int>>& matrix){
        for (size_t i = 0; i < matrix.size(); i++){
            for (size_t j = i; j < matrix[i].size(); j++)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
    
    void reverseM(vector<vector<int>>& matrix){
        for (size_t i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reverseM(matrix);
    }
};