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
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inorder(root, k, count);
    }

private:
    int inorder(TreeNode* node, int k, int& count) {
        //Base case: Zero node
        if(!node) return -1;

        //Traverse left branch for kth smallest value:
        int leftVal = inorder(node->left, k, count);
        if(count == k) return leftVal;

        //Process root node:
        ++count;
        if(count == k) return node->val; 

        //Traverse right branch for kth smallest value:
        return inorder(node->right, k, count);
    }
};