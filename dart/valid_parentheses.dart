/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if open brackets are closed by the same type of brackets and in the correct order.
*/

class Solution {
  bool isValid(String s) {
    final Map<String, String> pairs = {
      ')': '(',
      '}': '{',
      ']': '[',
    };
    final List<String> stack = [];

    for (int i = 0; i < s.length; i++) {
      final String char = s[i];

      if (pairs.containsValue(char)) {
        stack.add(char);
      } else if (stack.isEmpty || stack.removeLast() != pairs[char]) {
        return false;
      }
    }

    return stack.isEmpty;
  }
}
