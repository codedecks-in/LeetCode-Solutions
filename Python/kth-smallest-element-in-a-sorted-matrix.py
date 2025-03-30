'''
Difficulty: Medium
Time Complexity: O(n)
Space Complexity: O(1)
'''
class Solution:
    def kthSmallest(self, matrix, k):
        # Helper function to count how many numbers in 'matrix' are less than or equal to 'target'
        def matrixLessEqual(matrix, target):
            count, n = 0, len(matrix)  # Initialize count and get the size 'n' of the matrix
            row, column = n-1, 0  # Start from the bottom-left corner of the matrix

            # While our pointer is within the bounds of the matrix
            while row >= 0 and column < n:
                # If current element is less than or equal to target, 
                # add all elements in this column (from 0 to row) to the count
                # and move one step to the right
                if matrix[row][column] <= target:
                    count += row + 1
                    column += 1
                # If current element is larger than target,
                # move one step upwards
                else:
                    row -= 1
            return count  # Return the count
        
        n = len(matrix)  # Get the size 'n' of the matrix
        # Set initial search range for binary search to [smallest element, largest element]
        leftNumber, rightNumber = matrix[0][0], matrix[n-1][n-1]

        # While the search range [left, right] is valid
        while leftNumber < rightNumber:
            midValue = leftNumber + (rightNumber - leftNumber) // 2  # Compute mid-value of current search range

            # If count of elements less than or equal to 'mid' is less than 'k',
            # it implies the k-th smallest is in the upper half of search range.
            # So, update 'left' to be 'mid' + 1
            if matrixLessEqual(matrix, midValue) < k:
                leftNumber = midValue + 1
            # Else, the k-th smallest is in the lower half of search range.
            # So, update 'right' to be 'mid'
            else:
                rightNumber = midValue
        
        # When 'left' equals 'right', we have found the smallest value 
        return leftNumber

'''
Test Case 1:

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
Test Case 2:

Input: matrix = [[-5]], k = 1
Output: -5
'''
