// C++ stack based solution
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();

        stack<int> s;
        int curr = 0;
        int ans = 0;
        int tp;
        int i = 0;
        while (i < n) {
            if (s.empty() || h[s.top()] <= h[i]) s.push(i++);
            else {
                tp = s.top(); s.pop();
                if (s.empty()) curr = h[tp] * i;
                else  curr = h[tp] * (i - s.top() - 1);
                ans = max(ans, curr);
            }
        }
        while (!s.empty()) {
            tp = s.top(); s.pop();
            if (s.empty()) curr = h[tp] * i;
            else  curr = h[tp] * (i - s.top() - 1);
            ans = max(ans, curr);
        }
        return ans;
    }
};