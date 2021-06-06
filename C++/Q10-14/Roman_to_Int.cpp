#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:

    // Naive approach
    // Only speed up with unordered_map
    int romanToInt(string s) {
        unordered_map<char, int>converter;
        converter['I'] = 1;
        converter['V'] = 5;
        converter['X'] = 10;
        converter['L'] = 50;
        converter['C'] = 100;
        converter['D'] = 500;
        converter['M'] = 1000;
        
        if (s.length() == 1)
            return converter[s[0]];
        int prev_num = converter[s[0]];
        int curr_num;
        int result = prev_num;
        for (int i = 1; i < s.length(); i++){
            curr_num = converter[s[i]];
            if (curr_num > prev_num){
                result = result - 2 * prev_num + curr_num;
            }
            else{
                result += curr_num;
            }
            prev_num = curr_num;
        }
        return result;
    }
};