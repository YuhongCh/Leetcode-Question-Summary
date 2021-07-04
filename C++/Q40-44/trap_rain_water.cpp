#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int maxh = 0;
        int area = 0;
        for (int i = 0; i < (int)height.size(); i++){
            sum += height[i];
            maxh = max(maxh, height[i]);
            area += maxh;
        }
        maxh = 0;
        for (int i = height.size()-1; i >= 0; i--){
            maxh = max(maxh, height[i]);
            area += maxh;
        }
        area -= maxh * height.size();
        area = area - sum;
        return area;
    }
};