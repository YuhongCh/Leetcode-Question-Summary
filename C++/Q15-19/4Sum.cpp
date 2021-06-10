#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void twoSum(const vector<int>& nums, vector<vector<int>> &result, int target, int left, int numA, int numB){
        int right = nums.size() - 1;
        target = target - nums[numA] - nums[numB];
        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum < target) left++;
            else if (sum > target) right--;
            else{
                result.push_back(vector<int>{nums[left], nums[right], nums[numA], nums[numB]});
                left++;
                while (left < right && nums[left] == nums[left-1]) left++;
            }
        }
    }
    
    void FSum(const vector<int>& nums, vector<vector<int>>& result, int target, int k, int numA, int numB){
        if (k == 2){
            twoSum(nums, result, target, numB + 1, numA, numB);
            return;
        }
        if (k == 4){
            int size = nums.size()-3;
            for (int i = 0; i < size; ){
                FSum(nums, result, target, 3, i, numB);
                i++;
                while (i > 0 && i < size && nums[i] == nums[i-1]) i++;
            }
        }
        else if (k == 3){
            int size = nums.size()-2;
            for (int i = numA + 1; i < size;){
                FSum(nums, result, target, 2, numA, i);
                i++;
                while (i > 0 && i < size && nums[i] == nums[i-1]) i++;
            }
        }
    }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        FSum(nums, ans, target, 4, -1, -1);
        return ans;
        
    }
};