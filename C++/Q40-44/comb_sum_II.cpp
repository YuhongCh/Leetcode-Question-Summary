#include <vector>
#include <algorithm>
using namespace std;

// used a similar approach as the comb sum
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
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
        
        while (index < (int)candidates.size()){
            temp.push_back(candidates[index]);
            vectorSum(candidates, target-candidates[index], index+1, temp, res);
            temp.pop_back();
            index ++;
            while (index < (int)candidates.size() && candidates[index] == candidates[index-1]) index++;
        }
    }
};

// possible test case: {[2], 2}, {[2,2,2],2}, {[3,8],6}