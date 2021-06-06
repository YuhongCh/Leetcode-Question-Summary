#include <string>
#include <vector>

using namespace std;

class Solution {
public:

    // Used Greedy algorithm to loop from highest number to lowest number
    string intToRoman(int num) {
        vector<int> key = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> val = {"I",  "IV", "V",  "IX", "X",  "XL", "L", "XC", "C",  "CD", "D",  "CM", "M"};
        
        string result = "";
        
        for (int i = (int)key.size()-1; i >= 0; i--){
            int counter = num / key[i];
            if (counter == 0)
                continue;
            for (int temp = counter; temp > 0; temp--)
                 result +=val[i];
            num -= counter * key[i];
        }
        
        return result;
    }
};