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
    public TreeNode sortedArrayToBST(int[] nums) {
        // use merge sort strategy to convert sorted list to BST 
        return buildTree(0, nums.length-1, nums);
    }
    
    public TreeNode buildTree(int l, int r, int nums[]){
        // base case
        if(l>r) return null;
        // get mid of the whole index of the current list
        int mid = (l+r)/2;
        // create a node for mid of current subarray
        TreeNode node = new TreeNode(nums[mid]);
        // recurse for getting the left subtree
        node.left = buildTree(l, mid-1, nums);
        // recurse for getting the right subtree
        node.right = buildTree(mid+1, r, nums);
        // return the node
        return node;
    }
    
}
