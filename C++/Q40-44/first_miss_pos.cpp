#include <vector>

using namespace std;

// easy solution, with time O(n) and space O(n)
class Solution1 {
public:    
    int firstMissingPositive(vector<int>& nums) {
        vector<int> container(nums.size()+1, 0);
        for (int num : nums){
            if (num < 0 || num > nums.size()) continue;
            container[num] = 1;
        }
        for (int i = 1; i < (int)container.size(); i++){
            if (container[i] == 0) return i;
        }
        return container.size();
    }
};