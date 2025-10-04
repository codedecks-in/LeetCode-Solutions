// https://leetcode.com/problems/container-with-most-water
// code for the question : "container-with-most-water" 
// language : cpp


class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n = height.size();
            int max_area = 0;  // Variable to store the maximum water that can be contained
            int i = 0;         // Left pointer
            int j = n - 1;     // Right pointer
    
            // Use two-pointer approach to find the maximum area
            while (i < j) {
                // Calculate the area between the two current pointers
                int current_area = (j - i) * min(height[i], height[j]);
    
                // Update the maximum area found so far
                max_area = max(max_area, current_area);
    
                // Move the pointer with the smaller height
                if (height[i] < height[j]) {
                    i++;  // Move left pointer to the right
                } else {
                    j--;  // Move right pointer to the left
                }
            }
            return max_area;
        }
    };
    