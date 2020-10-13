

class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        string answer="";
        for(int i=0;i<str.length();i++)
        {
            if(s.empty())
                s.push(str[i]);
            else if(str[i]==s.top())
            {
                s.pop();
            }
            else
                s.push(str[i]);
        }
        while(!s.empty())
        {
            answer.push_back(s.top());  //pop values from stack and add it to back of the string answer(hense answer string is in reverse order)
            s.pop();
        }
        auto it=answer.rbegin();
        string val="";
        for (; it!=answer.rend(); it++) //this reverses the answer string
        {
            val.push_back(*it);
        }
        return val;
    }
};
