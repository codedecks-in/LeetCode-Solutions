/**
* Ransom Note
*
* Logic : character count in ransomNote should be equal to OR less than magazine character count.
* Runtime: 7 ms
* Memory Usage: 42.5 MB
*/
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        
        if (ransomNote.length() > magazine.length())
            return false;
        
        /* Logic : character count in ransomNote should be equal to OR less than magazine character count */
        
        int [] ransomNoteChCount = new int[26]; // lower case characters are only 26
        
        for (int i=0;i<ransomNote.length();i++){
            ransomNoteChCount[ransomNote.charAt(i) - 'a']++;
        }
        
        for (int i=0;i<magazine.length();i++){
            ransomNoteChCount[magazine.charAt(i) - 'a']--;
        }
        
        for(int i=0;i<26;i++){
            if (ransomNoteChCount[i] > 0){
                return false;
            }
        }
        
        return true;
    }
}
