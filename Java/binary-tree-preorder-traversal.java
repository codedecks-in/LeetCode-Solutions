/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 *
 * Runtime: 0 ms
 * Memory Usage: 37.9 MB	
 *
 */

class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ls = new ArrayList<Integer>();
        preorder(root, ls);
        return ls;
    }
    public void preorder(TreeNode root, List<Integer> ls){
	/* Preorder traversal is visiting : root then left subtree then right subtree */

	/* if node is null, then return back to the caller function */
        if(root==null)
            return;

	/* Add the current node's value to the list */
        ls.add(root.val);

	/* Recurse for left subtree */
        preorder(root.left, ls);

	/* Recurse for right subtree */
        preorder(root.right, ls);
    }
}