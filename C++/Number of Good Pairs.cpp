class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &i : nums) {
            mp[i]++;
        }
        int ans = 0;
        for(auto & i : mp) {
            ans += (i.second) * (i.second - 1) >> 1;
        }
        return ans;
    }
};
