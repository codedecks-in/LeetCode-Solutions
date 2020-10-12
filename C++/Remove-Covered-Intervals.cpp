//Problem Statement: Remove Covered Intervals

// Given a list of intervals, remove all intervals that are covered by another interval in the list.

// Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.

// After doing so, return the number of remaining intervals.

//Solution:
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
     
        int ans=0;
        for(int i=0; i<intervals.size(); i++) {
            for(int j=0; j<intervals.size(); j++) {
                if(i==j) continue;
                if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]) {
                    // cout << i << endl;
                    ans++; break;
                }
            }
        }
    
        return intervals.size()-ans;
    }
};

//Complexity: O(n*n)
