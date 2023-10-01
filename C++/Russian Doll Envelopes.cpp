// Optimized DP Approach with time and space Complexity
// Tag: Hard

bool comp(const pair<int, int> &x, const pair<int, int> &y) {
    if (x.first == y.first)
        return x.second > y.second;
    return x.first < y.first;
}

class Solution {
public:
     void solveLOGN(vector<int> &A, vector<int> &dp, int i, map<int,int> &m) {
        map<int,int>::iterator itr = m.upper_bound(A[i]);
        if(itr != m.end())
            dp[i] = itr->second + 1;
        else 
            dp[i] = 1;
        m[A[i]] = dp[i];
        map<int,int>::iterator it = m.lower_bound(A[i]);
        if(it != m.begin() && it->second >= prev(it)->second)
            m.erase(prev(it));
    }

    int findLIS(vector<int> &A) {
        int last = 10000;
        vector<int> dp(A.size()+1,0);
        map<int,int> m;
        int res = 1;
        for(int i = A.size()-1; i >= 0; i--) {
            solveLOGN(A, dp, i, m);
            res = max(res, dp[i]);
        }
        return res;
    }
    
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int> > pr;
        for (int i = 0; i < n; i++)
            pr.push_back({envelopes[i][0], envelopes[i][1]});
        sort(pr.begin(), pr.end(), comp);
        vector<int> A;
        for (int i = 0; i < pr.size(); i++)
            A.push_back(pr[i].second);
        return findLIS(A);
    }
};

// Time Complexity  -->  O(nlogn)
// Space Complexity -->  O(n)
