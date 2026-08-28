class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Get the number of rows and columns in the matrix
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Start from the top-right corner of the matrix
        int r = 0;
        int c = m - 1;
        
        // Loop until we reach either the bottom row or the leftmost column
        while (r < n and c > -1) {
            // If the current element is equal to the target, return true
            if (matrix[r][c] == target) {
                return true;
            }
            // If the current element is greater than the target, move left
            else if (matrix[r][c] > target) {
                c--;
            }
            // If the current element is less than the target, move down
            else {
                r++;
            }
        }
        
        // If the target is not found, return false
        return false;
    }
};
