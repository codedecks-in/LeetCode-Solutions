/**
* Reverse Words in a String
* Medium
* 
* Given an input string, reverse the string word by word

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"

Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
* 
* Runtime: 7 ms
* Memory Usage: 41.8 MB
*
*/
class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        
        String [] strArr = s.split(" ");
        
        String ans = "";
        
        for (int i=strArr.length-1; i>=0; i--) {
            if (strArr[i].isEmpty()){
        		continue;
        	}
            ans += strArr[i].trim() + " ";
        }
        
        return ans.trim();
    }
}
