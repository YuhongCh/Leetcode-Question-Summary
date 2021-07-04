#include <vector>
#include <string>
using namespace std;

// slow and memory consuming solution
// time: O(MN), memory: O(MN)
class Solution1 {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size()+1, vector<bool>(p.size()+1, false));
        dp[0][0] = true;
        // in the first row, give * a true value to prevent a lots of * exception
        for (int j = 0; j < (int)p.size() && p[j] == '*'; j++)
            dp[0][j+1] = true;

        // loop over entire MN space
        for (int i = 0; i < (int)s.size(); i++){
            for (int j = 0; j < (int)p.size(); j++){
                //if they can match, inherit the value from last match
                if (s[i] == p[j] || p[j] == '?')
                    dp[i+1][j+1] = dp[i][j];
                //if the value is *,
                //either moving right of table to stay in same s[i] character
                //or moving down the table to replace one s[i] character
                else if (p[j] == '*')
                    dp[i+1][j+1] = dp[i][j+1] || dp[i+1][j];
            }
        }
        return dp[s.size()][p.size()];
    }
};