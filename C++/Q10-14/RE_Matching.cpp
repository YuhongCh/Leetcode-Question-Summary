#include <vector>
#include <string>

using namespace std;



class Solution {
public:

    // This is Dynamic Programming Bottom up Approach
    /*//////////////////////////////////////////////////////////////////////////////////////
    The basic idea is to create a table with width p.length and height s.length
    We start from the very end with value 'true' and verify the string backward
    *//////////////////////////////////////////////////////////////////////////////////////
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1, vector<int>(p.length()+1, false));
        dp[s.length()][p.length()] = true;
        for (int row = s.length(); row >= 0; row--){
            for(int col = p.length()-1; col >= 0; col--){
                // if first_match is true, then pattern must have covered this letter
                // row >= s.length() only in first iteration, which enforce last row filled with false
                bool first_match = row < s.length() && (p[col] == '.' || p[col] == s[row]);
 
                if (col + 1 < p.length() && p[col+1] == '*'){
                    // set things before * to be true 
                    dp[row][col] = dp[row][col+2] || first_match && dp[row+1][col]; 
                }

                else{
                    // if we had find incorrect matching, we will always have false
                    dp[row][col] = first_match && dp[row+1][col+1];
                }
            }
        }
        return dp[0][0];
    }
};