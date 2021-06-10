#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> cha;
        for( int i = 0; i < (int)s.size(); ++i ){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                cha.push(s[i]);
            
            else if (s[i] == ')'){
                if( cha.empty() ) return false;
                if( cha.top() != '(' ) return false;
                cha.pop();
            }
            else if (s[i] == ']'){
                if( cha.empty() ) return false;
                if( cha.top() != '[' ) return false;
                cha.pop();
            }
            else if (s[i] == '}'){
                if( cha.empty() ) return false;
                if( cha.top() != '{' ) return false;
                cha.pop();
            }
                
        }
        if( cha.empty() ) return true;
        return false;
    }
};