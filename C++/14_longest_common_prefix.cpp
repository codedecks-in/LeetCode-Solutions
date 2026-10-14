/**
 * easy difficulty
 * runtime: 0ms
 * beats 100%
 *
 * memory: 11-12mb
 * beats 12-81%
 * (idk why but at 11.8mb of memory it beats 81% XD)
 */

class Solution {
constexpr static size_t THE_PREFIX_START_ = 0;

public:
    constexpr inline std::string longestCommonPrefix(const std::vector<string>& strs) noexcept {
        // considering a full string as the common_prefix
        std::string common_prefix{strs[0]};
        
        // looping throug every other string
        for(const auto& el : strs) {
            // looping while we don't find the common_prefix in el
            while(el.find(common_prefix) != THE_PREFIX_START_) {
                // shrinking the string a bit
                common_prefix = common_prefix.substr(0, common_prefix.size() - 1);
                // if our string is empty there is no common prefix among the strings
                if(common_prefix.empty()) {
                    return "";
                }
            }
        }

        return common_prefix;
    }
};
