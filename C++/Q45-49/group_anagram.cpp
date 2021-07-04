#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) return vector<vector<string>>{strs};
        unordered_map<string, vector<string>> memo;
        for (string str : strs){
            string str_copy = str;
            sort(str_copy.begin(), str_copy.end());
            if (memo.find(str_copy) == memo.end())
                memo[str_copy] = vector<string>{str};
            else
                memo[str_copy].push_back(str);
        }
        vector<vector<string>> result;
        for (unordered_map<string, vector<string>>::iterator it = memo.begin(); it != memo.end(); it++){
            result.push_back(it -> second);
        }
        return result;
    }
};