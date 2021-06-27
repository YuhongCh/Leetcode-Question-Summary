# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int divide_conquer(const vector<int>& nums, int target, int left, int right){
        if (left > right) return -1;
        if (left == right && nums[right] != target) return -1;
        int mid = (left + right) / 2;
        if (nums[left] > nums[right]){
            int res1 = divide_conquer(nums, target, left, mid);
            int res2 = divide_conquer(nums, target, mid+1, right);
            return max(res1, res2);
        }
        while (left <= right){
            if (target < nums[mid]) right = mid - 1;
            else if (target > nums[mid]) left = mid + 1;
            else return mid;
            mid = (left + right) / 2;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        return divide_conquer(nums, target, 0, nums.size()-1);
    }
};