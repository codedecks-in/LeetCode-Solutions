class Solution {
public:
    unordered_map<char,string> intToCharsMap;
    
    void backtracking(string::iterator lf,string::iterator rt,string &path,vector<string> &result)
    {
        if(lf == rt)
        {
            result.push_back(path);
            return;
        }
        for(auto c : intToCharsMap[*lf])
        {
            path.push_back(c);
            backtracking(next(lf,1),rt,path,result);
            path.pop_back();	// if a character doesnot matches then we pop that character from the string and again backtrack.
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        int n = digits.size();
        if(digits == "")
            return {};
        string path;
        // result array stores every string that represents that digit.
        vector<string> result;
        intToCharsMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        backtracking(digits.begin(),digits.end(),path,result);
        return result;
    }
};
