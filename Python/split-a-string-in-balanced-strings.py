class Solution:
    """
    Time Complexity: O(N)
    Space Complexity: O(1)
    """

    def balanced_string_split(self, s: str) -> int:
        # initialize variables
        L_count, R_count = 0, 0
        balanced_substring_count = 0

        # parse the string
        for char in s:

            # update the number of Ls and the number of Rs so far
            if char == 'L':
                L_count += 1
            elif char == 'R':
                R_count += 1

            # if the string is balanced, increment the balanced substrings count and reset the counters
            if L_count == R_count:
                balanced_substring_count += 1
                L_count, R_count = 0, 0
        return balanced_substring_count
