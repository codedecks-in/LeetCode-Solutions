#include <iostream>
#include <unordered_map>
#include <stack>

class Solution {
public:
    bool isValid(std::string s) {

        // Odd-length strings cannot be valid
        if(s.length() % 2 != 0) {
            return false;
        }

        // Map parentheses pairs
        std::unordered_map<char, char> parentheses = { {')', '('}, {']', '['}, {'}', '{'} };
        std::stack<char> characters;
        
        for (char current_char : s) {
            // Check if the current character is a closing parentheses
            if (parentheses.find(current_char) != parentheses.end()) {
                // If the stack is empty or the stack top doesn't match the current closing parentheses type, return false
                if (characters.empty() || characters.top() != parentheses[current_char]) {
                    return false;
                }
                // Otherwise, the parentheses match and the top element can be popped
                characters.pop();
            }
            else {
                // If current_char is not in the map, then that means it is an open parentheses, and can be pushed onto the stack
                characters.push(current_char);
            }
        }
        return characters.empty();
    }
};