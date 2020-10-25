#Time Complexity:   O(n)
#Space Complexity:  O(n)
#Speed: 98.14%
#Memory: 50.93%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root is None:
            return 0
        else:
            return max(self.maxDepth(root.left)+1, self.maxDepth(root.right)+1)