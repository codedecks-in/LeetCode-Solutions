/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.
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
  List<int> postorderTraversal(TreeNode? root) {
    final List<int> ans = [];
    postorder(root, ans);
    return ans;
  }

  void postorder(TreeNode? root, List<int> ans) {
    if (root == null) {
      return;
    }

    postorder(root.left, ans);
    postorder(root.right, ans);
    ans.add(root.val);
  }
}
