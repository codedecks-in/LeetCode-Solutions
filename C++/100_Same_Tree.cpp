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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr || q == nullptr) 
            return false;
        if(p->val != q->val) return false;
        
        return (isSameTree(p->right,q->right) && isSameTree(p->left, q->left));
    }
};

// Complexity Analysis:
// Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.
// Space complexity :O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree.