// We have to find different integer that are appearing in the given string. 
// "ab01c1d001" in this out output will be 1 as 01 1 001 are considered to be equal.
// so we use an hash map and we will remove starting zero from the numbers.
//then in last will return the size of out map to get the answer.
// this solution is O(n) time complexity and almost O(n) space complexity
class Solution {
public:
   void trim_zero(string& s){
    //To remove staring zero from out string
    int i = 0;
    string res ;
    while(s[i] == '0'){
        i++;
    }
    
    s = s.substr(i, s.length());
    
}

int numDifferentIntegers(string word) {
    
    int word_len = word.length();
    if(word_len == 0)
        return 0;
    
    int i = 0;
    string res;
    unordered_map<string, int> m;
    while(i < word_len){
        if(isdigit(word[i])){
            while(isdigit(word[i])){
                 res += word[i];
                i++;
            }
            trim_zero(res);
            
            m[res]++;
            res = "";
        }
       i++;
        
    }
    //This will give the number of unique integers we get from the string
    return m.size();
}
};
