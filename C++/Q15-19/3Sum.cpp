#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // with already set first pointer, we can do two sum algorithm on rest of vector
    void twoSum(const vector<int>& nums, vector<vector<int>>& result, int prev){
        int left = prev + 1;
        int right = nums.size() - 1;
        while (left < right){
            int sum = nums[prev] + nums[left] + nums[right];
            if (sum < 0)
                left++;
            else if (sum > 0)
                right--;
            else{
                result.push_back(vector<int>{nums[prev], nums[left], nums[right]});

                // update the pointer to prevent the duplicates
                left++;
                while(left < right && nums[left] == nums[left-1]) left++;
            }
        }
    }
    
    // setup one pointer such that we can simply do a 2Sum algorithm
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size() - 2;
        
        for(int prev = 0; prev < size; prev++){
           if(prev == 0 || nums[prev] != nums[prev-1]){
               twoSum(nums, result, prev);
           } 
        }
        return result;
    }
};