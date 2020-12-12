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
 */
class Solution {
    public boolean isBalanced(TreeNode root) {
        
        if(root==null){
            return true;
        }
        else{
            int left = height(root.left);
            int right = height(root.right);
            int diff = left - right;
            diff = diff > 0 ? diff : -diff; // absolute
            if(diff > 1){
                return false;
            }
            return isBalanced(root.left) && isBalanced(root.right);
        }
    }
    
    private int height(TreeNode root){
        // calculate the height of a tree
        if(root == null){
            return 0;
        }
        else{
            int left = height(root.left);
            int right = height(root.right);
            int height = left > right ? left : right;
            return height + 1;
        }
    }
}
