#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution1 {
public:

    // Native approach that uses the string library
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];
        for (int i = 0; i < (int)strs.size(); i++){
            while (strs[i].compare(0, prefix.length(), prefix) != 0){
                prefix.resize(prefix.length()-1);
            }
        }
        return prefix;
    }
};

class Solution2 {
public:
    // a wierd approach to use sort
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string prefix = "";
        string front = strs[0];
        string last = strs[strs.size()-1];
        int max_prefix_length = min(front.length(), last.length());
        for (int i = 0; i < max_prefix_length; i++){
            if (front[i] == last[i]){
                prefix += front[i];
            }
            else{
                break;
            }
        }
        return prefix;
    }
};