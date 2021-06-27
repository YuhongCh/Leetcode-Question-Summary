#include <vector>

using namespace std;

class Solution {
public:
    vector<int> extend_search(const vector<int>& nums, int index){
        int left = index;
        int right = index;
        while (left >= 0 && nums[left] == nums[index]) left--;
        while (right < nums.size() && nums[right] == nums[index]) right++;
        return vector<int>{left+1, right-1};
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] < target) left = mid + 1;
            else if (nums[mid] > target) right = mid - 1;
            else return extend_search(nums, mid);
        }
        return vector<int>{-1,-1};
    }
};