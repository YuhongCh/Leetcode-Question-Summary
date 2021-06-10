#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    // counter responsible for the number of ( used
    void recur_generate(vector<string>& result, string& ans, int counter, int index, int n){
        if (ans.length() == index){
            result.push_back(ans);
            return;
        }
        if (counter > 0){
            ans[index] = ')';
            recur_generate(result, ans, counter - 1, index + 1, n);
        }
        if (n){
            ans[index] = '(';
            recur_generate(result, ans, counter + 1, index + 1, n-1);
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string ans(2*n, '(');   // we can do all calculation with one string variable which reduce time and space usage
        recur_generate(result, ans, 1, 1, n-1);
        return result;
    }
};