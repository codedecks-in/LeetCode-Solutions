// Problem URL: https://leetcode.com/problems/generate-parentheses/
// Runtime: 8ms 
// Memory Usage: 8.4 MB

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        if(n==1){
            return {"()"};
        }
        
        vector<string> prev = generateParenthesis(n-1);
        
        set<string> s_ans;
        
        for(string s:prev){
            for(int i=0;i<s.size()+1;i++){
                string s2=s;
                s2.insert(i,"()");
                s_ans.insert(s2);
            }
        }
        
        vector<string> v_ans;
        for(string s:s_ans) v_ans.push_back(s);
        
        return v_ans;
    }
};
