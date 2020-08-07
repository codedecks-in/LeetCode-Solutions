/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 * Runtime: 0 ms
 * Memory Usage: 37.9 MB
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
	/* if root node of tree itself is null, then it's symmetric */
        if(root==null)
            return true;
        return checkMirror(root.left, root.right);
    }
    public boolean checkMirror(TreeNode lt, TreeNode rt){
	/* if root's left and root's right both are null, is then that subtree is symmetric */
        if(lt==null && rt==null)
            return true;

	/* if root's left is null and root's right is not null and vice-versa, is then that subtree is not symmetric */
        if((lt!=null && rt==null) || (lt==null && rt!=null))
           return false;

	/* check if left node's value matches with right node's value, and recursively check for their left and right subtrees */
        if(lt.val==rt.val && checkMirror(lt.left,rt.right) && checkMirror(lt.right,rt.left))
            return true;

        return false;
    }
}