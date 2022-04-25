class Solution {
    vector<string> result;
public:
    vector<string> restoreIpAddresses(string s) {
        
        if(s.size()<4 || s.size() > 12)  return result;
        
        helper(0, 0, "", s);
        return result;
    }
    
    void helper(int i, int dots, string buffer, string s){
        if(dots == 3){
            if(isValid(s.substr(i)))
                result.push_back(buffer+s.substr(i));
            
            return;
        }
        
        for(int j=i; j< s.size(); j++){
            if(isValid(s.substr(i, j-i+1))){
                buffer.push_back(s[j]);
                buffer.push_back('.');
                helper(j+1, dots+1, buffer, s);
                buffer.pop_back();
            }
        }
    }
    
    bool isValid(string s1){
        if(s1.size() > 3 || s1.size() == 0)     return false;
        
        if(s1.size() > 1 && s1[0] == '0')   return false;
        
        if(s1.size()>0 && stoi(s1)>255)     return false;
        
        return true;
    }
};
