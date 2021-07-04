#include <vector>
#include <unordered_set>
using namespace std;

// very time consuming solution as hash function does a lot of multiplication
class Solution1 {
public:
    unordered_set<int>extracted;
    vector<vector<int>> result;
    
    int hash(const vector<int>& nums){
        int result = 0;
        for (size_t i = 0; i < nums.size(); i++){
            result += nums[i] * pow(10, i);
        }
        return result;
    }
    
    void find_permutation(vector<int> &nums, int index){
        if (index == nums.size()){
            int hash_result = hash(nums);
            if (extracted.find(hash_result) == extracted.end()){
                extracted.insert(hash_result);
                result.push_back(nums);
            }
            return;
        }
        for (int i = index; i < nums.size(); i++){
            swap(nums[index], nums[i]);
            find_permutation(nums, index+1);
            swap(nums[index], nums[i]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        nums.reserve(nums.size());
        find_permutation(nums, 0);
        return result;
    }
};