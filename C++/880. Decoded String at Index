class Solution {
public:
    std::string decodeAtIndex(std::string inputString, int k) {
        long long decodedLength = 0; // Total length of the decoded string
        for (auto character : inputString) {
            if (isdigit(character)) {
                // If the character is a digit, update the decoded length accordingly
                decodedLength *= character - '0';
            } else {
                // If the character is a letter, increment the decoded length
                decodedLength++;
            }
        }

        // Traverse the input string in reverse to decode and find the kth character
        for (int i = inputString.size() - 1; i >= 0; i--) {
            if (isdigit(inputString[i])) {
                // If the character is a digit, adjust the length and k accordingly
                decodedLength /= (inputString[i] - '0');
                k = k % decodedLength;
            } else {
                // If the character is a letter, check if it's the kth character
                if (k == 0 || decodedLength == k)
                    return string("") + inputString[i]; // Return the kth character as a string
                decodedLength--;
            }
        }

        return ""; // Return an empty string if no character is found
    }
};
