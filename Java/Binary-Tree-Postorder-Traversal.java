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
    List<Integer> list = new ArrayList<Integer>();
    public List<Integer> postorderTraversal(TreeNode root) {
        postorder(root);
        return list;
    }

    public void postorder(TreeNode root){
	/* Postorder traversal is visiting : left subtree then right subtree then root */

	/* if node is null, then return back to the caller function */
        if(root==null)
            return;
	
	/* Recurse for left subtree */
        postorderTraversal(root.left);

	/* Recurse for right subtree */
        postorderTraversal(root.right);

	/* Add the current node's value to the list */
        list.add(root.val);
    }
}
