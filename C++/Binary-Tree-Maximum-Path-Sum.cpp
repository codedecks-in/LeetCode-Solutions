/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * Runtime : 40ms
 * Memory : 28.5 MB
 * 
 *
 */
class Solution {
public:
    
    int solve(TreeNode* root, int &ans)
    {
        if(root == NULL)
            return 0;
   	
	# to traverse left and right childs     
        int l = solve(root->left, ans);
        int r = solve(root->right, ans);
        
	/* to find max sum including root_val and left and child subtree
	   max sum or just including root val if result from subtree is -  		   negative
	*/ 
        int temp = max(max(l,r)+root->val, root->val);

	/* in case max sum does not include main root and 
	   forms maximum sum path through sub tree
	*/
        int res = max(temp, root->val+l+r);
        ans = max(res,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
     int ans = INT_MIN;
        solve(root,ans);
        return ans;
        
    }
};
