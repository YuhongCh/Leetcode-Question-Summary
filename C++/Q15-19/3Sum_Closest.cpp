#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // used a 2 pointer approach which mimic the 3Sum algoirithm
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int diff = INT_MAX;
        
        // this is the first index fixed
        for(int prev = 0; prev < size && diff != 0; prev++){

            // the while loop below search for left and right best index
            int left = prev + 1, right = size - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[prev];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                    // this return result immediately as find the answer
                    // save a lot of time when result has difference 0
                else return target;
            }
            
        }
        return target - diff;
        
    }
};