# include <unordered_map>
# include <string>
# include <vector>

using namespace std;

class Solution {
public:
    void permutation(unordered_map<char, vector<char>>& letters, const string& digits, vector<string>& result, string res, int index){
        if (res.length() == digits.length()){
            result.push_back(res);
            return;
        }
        char key = digits[index];
        for(int i = 0; i < (int)letters[key].size(); i++){
            permutation(letters, digits, result, res + letters[key][i], index + 1);
        }
            
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0){
            return vector<string>{};
        }
        
        unordered_map<char, vector<char>> letters;
        letters['2'] = vector<char>{'a', 'b', 'c'};
        letters['3'] = vector<char>{'d', 'e', 'f'};
        letters['4'] = vector<char>{'g', 'h', 'i'};
        letters['5'] = vector<char>{'j', 'k', 'l'};
        letters['6'] = vector<char>{'m', 'n', 'o'};
        letters['7'] = vector<char>{'p', 'q', 'r', 's'};
        letters['8'] = vector<char>{'t', 'u', 'v'};
        letters['9'] = vector<char>{'w', 'x', 'y', 'z'};
        
        vector<string>result;
        int vec_size = 1;
        for (char c : digits) vec_size *= letters[c].size();
        result.reserve(vec_size);
        permutation(letters, digits, result, "", 0);
        
        return result;
    }
};