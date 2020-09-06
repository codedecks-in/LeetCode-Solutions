/**
* First Unique Character in a String
*
* Time complexity - O(n)
* Space complexity - O(1)
*/
class Solution {
    public int firstUniqChar(String s) {
        int len = s.length();
        
        // check if string is null or empty
        if(s == null || s.isEmpty()){
            return -1;
        }
        
        // Note: You may assume the string contains only lowercase English letters.
        int []ch = new int[26];
        
        // count chars and store it in ch array
        for(int i=0; i<len; i++){
            ch[s.charAt(i) - 'a']++;
        }
        
        // again traverse and if count is 1 that means it occurs only once
        for(int i=0; i<len; i++){
            if(ch[s.charAt(i) - 'a'] == 1){
                return i;
            }
        }
        
        // else return -1
        return -1;
    }
}
