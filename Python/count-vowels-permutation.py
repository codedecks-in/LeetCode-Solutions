"""
This problem is truly amazing, you can find my write-up here:
https://leetcode.com/problems/count-vowels-permutation/solutions/3040891/python-4-solutions-slowly-getting-better-thought-process-beats-99/
"""



import numpy as np


class Solution:
    def countVowelPermutation(self, n: int) -> int:
        mat = np.array(
            [
                [0, 1, 1, 0, 1],
                [1, 0, 1, 0, 0],
                [0, 1, 0, 1, 0],
                [0, 0, 1, 0, 0],
                [0, 0, 1, 1, 0],
            ],
            dtype=int,
        )
        result = np.eye(5, dtype=int)
        n -= 1
        while n:
            if n % 2:
                result = np.dot(result, mat) % (10**9 + 7)
            mat = np.dot(mat, mat) % (10**9 + 7)
            n //= 2
        return np.sum(result) % (10**9 + 7)
