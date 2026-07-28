/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.
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
  List<int> preorderTraversal(TreeNode? root) {
    final List<int> ans = [];
    preorder(root, ans);
    return ans;
  }

  void preorder(TreeNode? root, List<int> ans) {
    if (root == null) {
      return;
    }

    ans.add(root.val);
    preorder(root.left, ans);
    preorder(root.right, ans);
  }
}
