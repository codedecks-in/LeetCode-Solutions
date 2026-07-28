/*
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal substring consisting of non-space characters only.
*/

class Solution {
  int lengthOfLastWord(String s) {
    int index = s.length - 1;
    int length = 0;

    while (index >= 0 && s[index] == ' ') {
      index--;
    }

    while (index >= 0 && s[index] != ' ') {
      length++;
      index--;
    }

    return length;
  }
}
