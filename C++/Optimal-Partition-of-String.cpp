class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> table;
        int count = 1;
        
        for(int i=0; i<s.size(); i++){
            if(table.count(s[i])){
                count++;
                table.clear();
                table.insert(s[i]);
            }
            else{
                table.insert(s[i]);
            }
        }
        
        return count;
    }
};