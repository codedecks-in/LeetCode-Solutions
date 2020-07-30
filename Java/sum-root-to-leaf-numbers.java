/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 * 
 *  Runtime: 0 ms
    Memory Usage: 39.2 MB
 */

class Solution {
    int sum = 0;

    public int sumNumbers(TreeNode root) {
        traverse(root, 0);
        return sum;
    }

    public void traverse(TreeNode root, int n) {
        // if the node is null, return from the function (specially to handle if root of
        // tree is null)
        if (root == null)
            return;
        // shift the previous units place digit to ten's place by multiplying it by 10
        // and add the current value of node
        n = n * 10 + root.val;
        // if the node does not have a left or right children is null,
        // the current node is leaf node, so add the value to sum and return
        if (root.left == null && root.right == null) {
            sum += n;
            return;
        }
        // recurse for left subtree
        traverse(root.left, n);
        // recurse for right subtree
        traverse(root.right, n);
    }
}