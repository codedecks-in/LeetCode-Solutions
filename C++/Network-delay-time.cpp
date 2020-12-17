//Time complexity O(V+E)
//Space Complexity O(V)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<long long int> d(N + 1, INT_MAX);
        d[K] = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < times.size(); ++j) {
                if (d[times[j][1]] > d[times[j][0]] + times[j][2]) {
                    d[times[j][1]] = d[times[j][0]] + times[j][2];
                }
            }
        }
        
        int a = *max_element(d.begin() + 1, d.end());
        return a >= INT_MAX ? -1 : a;
    }
};