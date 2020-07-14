/**
 * Jewels and Stones
 * 
 * You're given strings J representing the types of stones that are jewels, and
 * S representing the stones you have. Each character in S is a type of stone
 * you have. You want to know how many of the stones you have are also jewels.
 * 
 * The letters in J are guaranteed distinct, and all characters in J and S are
 * letters. Letters are case sensitive, so "a" is considered a different type of
 * stone from "A".
 * 
 * @author gouravrusiya
 *
 */
public class Solution {
	public int numJewelsInStones(String J, String S) {

		int[] asciiCount = new int[128];
		int ch;

		for (int i = 0; i < S.length(); i++) {
			// get ASCII of character
			ch = S.charAt(i);
			asciiCount[ch]++;
		}

		int jewelsCount = 0;

		// iterate through Jewels for stones type
		for (int i = 0; i < J.length(); i++) {
			ch = J.charAt(i);
			jewelsCount += asciiCount[ch];
		}

		return jewelsCount;
	}
}