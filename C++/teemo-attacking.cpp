//https://leetcode.com/problems/teemo-attacking/
//Difficulty Level: Medium 
//Tags: Arrays
//Time complexity: O(n)
//Space complexity: O(1)
//similar to overlapping subintervals problems

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int n = timeSeries.size();
        if(n==0)
            return 0;
        
        int ans = duration;
        
        for(int i=0; i<n-1; i++)
        {
            ans += duration;
            if(timeSeries[i+1] < timeSeries[i] + duration)  //overlapping condition
            {
                ans -= (timeSeries[i] + duration - timeSeries[i+1]);   //the overlapped time subtracted
            }
        }
        
        return ans;
    }
};