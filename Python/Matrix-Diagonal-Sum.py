from typing import List

class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        diagonal_sum = 0
        for i in range(n):
            diagonal_sum += mat[i][i]
            if i != n - 1 - i:
                diagonal_sum += mat[i][n - 1 - i]
        return diagonal_sum