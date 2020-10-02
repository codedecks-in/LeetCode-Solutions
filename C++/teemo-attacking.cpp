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
            if(timeSeries[i+1] < timeSeries[i] + duration)  //overlapping
            {
                ans -= (timeSeries[i] + duration - timeSeries[i+1]);
            }
        }
        
        return ans;
    }
};