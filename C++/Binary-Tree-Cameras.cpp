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
    int ans=0;
    unordered_set<TreeNode*> covered;
    void dfs(TreeNode* root,TreeNode* parent){
        if(root==NULL)  
            return;
        dfs(root->left,root);
        dfs(root->right,root);
        if((parent==NULL && covered.find(root)==covered.end()) || covered.find(root->left)==covered.end() || covered.find(root->right)==covered.end()){
            ans++;
            covered.insert(root);
            covered.insert(parent);
            covered.insert(root->left);
            covered.insert(root->right);
        }
    }
    int minCameraCover(TreeNode* root) {
        covered.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
};
