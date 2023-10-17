#include <bits/stdc++.h>

using namespace std;

int numIdenticalPairs(vector<int>& nums) {
    unordered_map<int, int> count;

    // Count the occurrences of each number
    for (int num : nums) {
        count[num]++;
    }

    int goodPairs = 0;

    // Calculate the number of good pairs for each number
    for (const auto& pair : count) {
        int occurrences = pair.second;
        if (occurrences >= 2) {
            goodPairs += (occurrences * (occurrences - 1)) / 2;
        }
    }

    return goodPairs;
}

int main() {
    vector<int> nums = {1, 2, 3, 1, 1, 3, 4};
    int result = numIdenticalPairs(nums);
    cout << "Number of Good Pairs: " << result << endl;

    return 0;
}
