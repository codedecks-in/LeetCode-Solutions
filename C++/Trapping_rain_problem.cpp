// Difficulty = Hard
// Submission Speed = 99.99%

// Test case 1
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Test case 2
// Input: height = [4,2,0,3,2,5]
// Output: 9

//The solution to the problem is 
// First we will traverse the array from left and find max element on the left to the selected element 
// Second, we will traverse the array from right and find max element on the right to the selected element
// Then, we'd be able to store the area between them to get the area of the trapped water.
// Take a variable which will store the sum of all the trapped water area and return it.

// Time complexity - 0(N)
// Space complexity - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int mxl[height.size()];
        int mxr[height.size()];
        
        mxl[0] = height[0];
        mxr[height.size()-1] = height[height.size()-1];
        
        for(int i=1; i<height.size(); i++)
            mxl[i] = max(mxl[i-1], height[i]);
        for(int i=height.size()-2; i>=0; i--)
            mxr[i] = max(mxr[i+1], height[i]);

        int mx=0;
        
        for(int i=0; i<height.size(); i++)
            mx += min(mxl[i], mxr[i]) - height[i];

        return mx;
    }
};