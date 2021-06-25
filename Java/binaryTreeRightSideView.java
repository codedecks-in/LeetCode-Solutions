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
/*
Time Complexity : O(n)
Space Complexity : O(n)

Recursive call is made to right subtree and then the left subtree
Note : if current level is greater than the max level we have visited rightmost node 
*/

class Solution {
    static int maxLevel;
    public static List<Integer> rightSideView(TreeNode root) {
     
        maxLevel = 0;
        int level = 1;
        List<Integer> result = new ArrayList<Integer>();
        rightSideViewHelper(root,level,result);
        
        return result;
    }
    public static void rightSideViewHelper(TreeNode root,int level,List<Integer> result) 
    {
        if(root == null)
        {
            return; 
        }
        
        if(maxLevel < level)
        {
            maxLevel = level;
            result.add(root.val);
        }
        
        rightSideViewHelper(root.right,level+1,result);
        rightSideViewHelper(root.left,level+1,result);
    }
}
