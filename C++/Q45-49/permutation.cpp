#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int factorial(int n){
        int res = 1;
        for (int i = 2; i <= n; i++)
            res *= i;
        return res;
    }
    
    void find_permutation(vector<int> &nums, int index, vector<int>& temp, vector<vector<int>>&result){
        if (index == nums.size()){
            result.push_back(temp);
            return;
        }
        for (int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            temp.push_back(nums[index]);
            find_permutation(nums, index+1, temp, result);
            temp.pop_back();
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int> temp;
        result.reserve(factorial(nums.size()));
        temp.reserve(nums.size());
        find_permutation(nums, 0, temp, result);
        return result;
    }
};