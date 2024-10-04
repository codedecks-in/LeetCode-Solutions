#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        // Step 1: Create a copy of the array and sort it
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        // Step 2: Create a map to hold the rank of each unique element
        std::unordered_map<int, int> rankMap;
        int rank = 1;

        // Assign ranks, skipping duplicates
        for (int i = 0; i < sortedArr.size(); ++i) {
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank++;
            }
        }

        // Step 3: Replace elements in the original array with their ranks
        std::vector<int> result(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            result[i] = rankMap[arr[i]];
        }

        return result;
    }
};