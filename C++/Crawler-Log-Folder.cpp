class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;  //stack s is initialized and stack is empty when you are on main folder
        for(int i=0;i<logs.size();i++){
            if (logs[i]=="../" && !s.empty()){  //if string is "../" and stack is not empty then go back one folder
                s.pop();
            }
            else if((logs[i]=="./") || (logs[i]=="../" && s.empty())) {  //if string is "./" or stack is empty and string is "../" then do nothing
                continue;
            }
            else {  // otherwise push the new folder on top of stack
                s.push(logs[i]);
            }
        }
        return s.size();  //number of steps required to go back to main folder will be equal to the number of elements remaining in the stack
    }
};