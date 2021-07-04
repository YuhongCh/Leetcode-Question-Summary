#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) 
            return 0;
        
        int max_index_jump = 0;
        int max_jump_i = 0;
        int tot_jump = 0;
        
        int current_distance;
        
        for (size_t i = 0; i < nums.size() - 1; i++){
            current_distance = nums[i] + i;
            if (max_jump_i < current_distance)
                max_jump_i = current_distance;
            

            if (max_index_jump == i){
                tot_jump++;
                max_index_jump = max_jump_i;
                
            }
                
        }
        return tot_jump;
    }
};