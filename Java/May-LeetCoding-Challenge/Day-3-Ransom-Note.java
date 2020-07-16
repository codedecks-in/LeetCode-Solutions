/**
 * Ransom Note
 * 
 * Given an arbitrary ransom note string and another string containing letters
 * from all the magazines, write a function that will return true if the ransom
 * note can be constructed from the magazines ; otherwise, it will return false.
 * 
 * Each letter in the magazine string can only be used once in your ransom note.
 * 
 * @author gouravrusiya
 *
 */
public class Solution {
	public boolean canConstruct(String ransomNote, String magazine) {

		if (ransomNote.length() > magazine.length())
			return false;

		/*
		 * Logic : character count in ransomNote should be equal to OR less than
		 * magazine character count
		 */

		int[] ransomNoteChCount = new int[26]; // lower case characters are only 26

		for (int i = 0; i < ransomNote.length(); i++) {
			ransomNoteChCount[ransomNote.charAt(i) - 'a']++;
		}

		for (int i = 0; i < magazine.length(); i++) {
			ransomNoteChCount[magazine.charAt(i) - 'a']--;
		}

		for (int i = 0; i < 26; i++) {
			if (ransomNoteChCount[i] > 0) {
				return false;
			}
		}

		return true;
	}
}
