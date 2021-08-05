#include <list>
#include <string>
/*
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true
*/

class Solution {
public:
    bool isValid(string s) {
        list<char> open;
        if(s.length()%2!=0)
            return false;
        for(int i=0; i<s.length();i++){
            if(s[i]=='{'||s[i]=='['||s[i]=='(')
                open.push_front(s[i]);
            else{
                switch(s[i]){
                    case '}':
                        if(open.front()!='{')
                            return false;
                        break;
                    case ']':
                        if(open.front()!='[')
                            return false;
                        break;
                    case ')':
                        if(open.front()!='(')
                            return false;
                        break;
                    default :
                        return true;
                }
                open.pop_front();
            }    
        }
        if(open.size()!=0)
            return false;
    return true;
    }
};