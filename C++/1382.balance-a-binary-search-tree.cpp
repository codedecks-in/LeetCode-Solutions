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
    vector<TreeNode*> vec;
    void inorder(TreeNode* root){
        if(root==nullptr)   return;
        inorder(root->left);
        vec.push_back(root);
        inorder(root->right);        
    }
    
    TreeNode* sortedToBST(int a, int b){
        if(a>b) return nullptr;
        int mid = (a+b)/2;
        TreeNode* temp  = vec[mid];
        temp->left = sortedToBST(a,mid-1);
        temp->right = sortedToBST(mid+1,b);
        return temp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return sortedToBST(0,vec.size()-1);
    }
};
