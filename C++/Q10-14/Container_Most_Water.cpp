#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    // two pointer solution
    // easy enough, no explanation needed
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        while (left < right){
            if (height[left] < height[right]){
                int curr_area = height[left] * (right - left);
                area = max(area, curr_area);
                left++;
            }
            else{
                int curr_area = height[right] * (right - left);
                area = max(area, curr_area);
                right--;
            }
        }
        return area;
    }
};