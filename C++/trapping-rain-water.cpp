// https://leetcode.com/problems/trapping-rain-water/

// Idea: 
// We calculate the prefix and suffix max arrays 
// The water trapped would be the min of the 2 arrays at a particular index minus the actual height 

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        if(n==0) return 0;
        
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0] = height[0];
        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1],height[i]);
        }
        
        suffix[n-1] = height[n-1];
        for(int i = n-2; i>=0; i--){
            suffix[i] = max(suffix[i+1],height[i]);
        }
        
        int ans = 0;
        for(int i = 0; i<n; i++){
            int x = min(prefix[i],suffix[i])-height[i];
            if(x>0) ans+=x;         
        }
        
        return ans;
    }
};