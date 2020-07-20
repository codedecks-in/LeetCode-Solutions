/**
* Given two strings s and t , write a function to determine if t is an anagram of s.
*
* Note:
* You may assume the string contains only lowercase alphabets.

* Follow up:
* What if the inputs contain unicode characters? How would you adapt your solution to such case?
* 
* Works for any unicode characters - 128 unicode chars are there.
* 
* Time: O(n)
* Space: O(1) [because the table's size stays constant no matter how large n is]
*/
class Solution {
    public boolean isAnagram(String s, String t) {
        
        int [] charCount = new int[128];
        
        for (int i=0; i<s.length(); i++){
            charCount[s.charAt(i)]++;
        }
        
        for (int i=0; i<t.length(); i++){
            charCount[t.charAt(i)]--;
        }
        
        for (int i=0;i<128;i++){
            if(charCount[i] != 0){
                return false;
            }
        }
        
        return true;
    }
}
