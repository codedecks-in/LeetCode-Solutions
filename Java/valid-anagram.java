/**
* Given two strings s and t , write a function to determine if t is an anagram of s.
*
* Note:
* You may assume the string contains only lowercase alphabets.

* Follow up:
* What if the inputs contain unicode characters? How would you adapt your solution to such case?
* 
* Works for any ASCII characters - 128 ASCII chars are there.
* for unicode chars - 256 chars are there.
*/
class Solution {
    
    // 1. Brute force approach
    // Time Complexity: O(n2) | Space Complexity: O(1)
    public boolean isAnagramUsingBruteForce(String s, String t) {
        
        if (s.length() != t.length()){
            return false;
        }
        else if(s.isEmpty()){
            return true;
        }
        
        boolean isAnagram = false;
        
        boolean [] visited = new boolean[t.length()];
        
        for(int i=0; i<s.length(); i++){
            isAnagram = false;
            
            for(int j=0; j<t.length(); j++){
                if(s.charAt(i) == t.charAt(j) && !visited[j]){
                    isAnagram = true;
                    visited[j] = true;
                    break;
                }
            }
            
            if(!isAnagram){
                return false;
            }
        }
        
        return isAnagram;
    }
    
    // 2. Sorting approach
    // Time Complexity: O(nlogn) | Space Complexity: O(n) 
    public boolean isAnagramUsingSorting(String s, String t) {
        
		// length check
        if (s.length() != t.length()){
            return false;
        }
		else if(s.isEmpty()){ // empty string check
            return true;
        }
        
        char [] ch1 = s.toCharArray();
        char [] ch2 = t.toCharArray();
        
		// sort both arrays
        Arrays.sort(ch1);
        Arrays.sort(ch2);
		
        return Arrays.equals(ch1, ch2); // compare each character at same position or index
    }
    
    // 3. Efficient approach using hashing
    // Time: O(n) | Space: O(1) [because the table's size stays constant no matter how large n is]
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
