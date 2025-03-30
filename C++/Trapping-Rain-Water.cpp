//https://leetcode.com/problems/trapping-rain-water/
//Difficulty Level: Hard 

/*Complexity
Time complexity:O(n) Space complexity:O(1)
*/

/*
Context and Motivation:
Imagine the elevation heights in the array as a landscape, and the bars as buildings. 
Rainwater can be trapped between the buildings, and the goal is to calculate the volume of trapped water. 
This problem has real-world applications in understanding water flow in various terrains, such as urban planning and hydrology.

Approach:
The provided code is an implementation of the two-pointer approach to solve the 
trapping rainwater problem efficiently.

*/

class Solution {
public:
    int trap(vector<int>& h) {
        int total = 0;                  // Initialize the variable to store the total trapped water
        int l = 0, r = h.size() - 1;    // Initialize left and right pointers
        int left_max = h[l];            // Initialize the maximum height from the left to the first element
        int right_max = h[r];           // Initialize the maximum height from the right to the last element
        
        while (l + 1 < r) {             // Continue while there are at least 3 elements between left and right pointers
            if (h[l] <= h[r]) {         // If the height at the left pointer is less than or equal to the right pointer
                ++l;                    // Move the left pointer to the right
                total += max(0, left_max - h[l]);  // Calculate trapped water on the left side
                left_max = max(left_max, h[l]);    // Update the maximum height from the left
            } else {                    // If the height at the left pointer is greater than the right pointer
                --r;                    // Move the right pointer to the left
                total += max(0, right_max - h[r]); // Calculate trapped water on the right side
                right_max = max(right_max, h[r]);  // Update the maximum height from the right
            }
        }

        return total; // Return the total trapped water    
    }
};

