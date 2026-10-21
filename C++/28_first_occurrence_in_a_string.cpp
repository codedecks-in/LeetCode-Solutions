/**
 * easy difficulty
 * runtime: 0ms
 * beats 100%
 *
 * memory: 8.85mb
 * beats 99.68%
 */

class Solution {
public:
    /**
     * @brief a function will return the index of the first occurence of
     * a string in the main string
     * @param haystack is the main string that the search will be applied to
     * @param needle is the string that the function will search for
     * @return the index of the first occurence of 'needle' in 'haystack' if
     * found ; std::string::npos (or -1) otherwise
     */
    constexpr inline int strStr(const string& haystack, const string& needle) noexcept {
        // using built in functions to find the index of the
        // first occurence of the 'needle' in the 'haystack'
        // and if 'needle' isn't present, it will return std::string::npos (-1)
        return haystack.find(needle);
    }
};
