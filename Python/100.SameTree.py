#Time Complexity:   O(n)
#Space Complexity:  O(n)
#Speed: 98.83%
#Memory: 13.23%

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:

    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        result = []
        self.preorder(p, q, result)
        return min(result)

    def preorder(self, p, q, result):
        if not p and not q:
            result.append(True)
            return
        if not p or not q:
            result.append(False)
            return
        if p.val != q.val:
            result.append(False)
        if p.val == q.val:
            result.append(True)
            self.preorder(p.left, q.left, result)
            self.preorder(p.right, q.right, result)