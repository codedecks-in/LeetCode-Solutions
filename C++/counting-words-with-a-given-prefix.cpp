class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i<words.size(); i++){
            bool isok = false;
            for(int j = 0; j< pref.size(); j++){
                if(words[i][j]==pref[j]){
                    isok = true;
                }
                else{
                    isok = false;
                    break;
                }
            }
            if(isok)count++;
        }
        return count;
    }
};


//Time complexity: O(n*m), where n = number of words , m = length of the prefix
//Space complexity: O(1)