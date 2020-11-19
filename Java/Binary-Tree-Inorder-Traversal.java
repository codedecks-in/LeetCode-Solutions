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
 * Memory Usage: 37.8 MB
 *
 */

class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list = new ArrayList<Integer>();
        inorder(root, list);
        return list;
    }

    public void inorder(TreeNode root, List<Integer> list){
	/* Inorder traversal is visiting : left subtree then root then right subtree */

	/* if node is null, then return back to the caller function */
        if(root==null)
            return;
	/* Recurse for left subtree */
        inorder(root.left, list);

	/* Add the current node's value to the list */
        list.add(root.val);

	/* Recurse for right subtree */
        inorder(root.right, list);
    }
}
