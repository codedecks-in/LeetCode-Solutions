/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
*/

/*
Definition for a binary tree node.
class TreeNode {
  int val;
  TreeNode? left;
  TreeNode? right;
  TreeNode([this.val = 0, this.left, this.right]);
}
*/

class Solution {
  List<int> inorderTraversal(TreeNode? root) {
    final List<int> ans = [];
    inorder(root, ans);
    return ans;
  }

  void inorder(TreeNode? root, List<int> ans) {
    if (root == null) {
      return;
    }

    inorder(root.left, ans);
    ans.add(root.val);
    inorder(root.right, ans);
  }
}
