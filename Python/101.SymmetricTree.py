#Time Complexity:   O(n)
#Space Complexity:  O(n)
#Speed: 95.44%
#Memory: 23.72%

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        queue = [root]
        while queue:
            length = len(queue)
            level = []
            while length:
                node = queue.pop(0)
                level.append(node.val if node else None)
                length -= 1
                if node:
                    queue.append(node.left)
                    queue.append(node.right)
            i = 0
            j = len(level) - 1
            while i <= j:
                if level[i] != level[j]:
                    return False
                i += 1
                j -= 1
        return True