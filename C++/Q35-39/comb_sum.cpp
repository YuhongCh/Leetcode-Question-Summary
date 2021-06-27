#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int>temp;
        vectorSum(candidates, target, 0, temp, result);
        return result;
    }
    
    void vectorSum(const vector<int>& candidates, int target, int index, vector<int>& temp, vector<vector<int>>& res){
        if (target == 0){
            res.push_back(temp);
            return;
        }
        if (target < 0) return;
        
        for (; index < (int)candidates.size(); index++){
            temp.push_back(candidates[index]);
            vectorSum(candidates, target-candidates[index], index, temp, res);
            temp.pop_back();
        }
    }
};