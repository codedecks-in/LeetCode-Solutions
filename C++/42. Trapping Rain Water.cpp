/*difficulty: hard*/
/*  question link: https://leetcode.com/problems/trapping-rain-water/  */

class Solution {
public:
    int trap(vector<int>& height)
    {
    int heightSize = height.size();

    int res = 0;

    int lmax[heightSize], rmax[heightSize];

    lmax[0] = height[0];
    for (int i = 1; i < heightSize; i++)
    {
        lmax[i] = max(height[i], lmax[i - 1]);
    }

    rmax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--)
    {
        rmax[i] = max(height[i], rmax[i + 1]);
    }

    for (int i = 1; i < heightSize - 1; i++)
    {
        res = res + (min(lmax[i], rmax[i]) - height[i]);
    }

    return res;
}

// test case 1
// height = [0,1,0,2,1,0,1,3,2,1,2,1]
// output = 6

// test case 2
// height = [4,2,0,3,2,5]
// output = 9

// time complexity --> O(n)
        
    
};