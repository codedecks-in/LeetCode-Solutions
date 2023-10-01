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
    void inorder(vector<int> &in, TreeNode* root){
        if(root == NULL)
            return;
        
        inorder(in, root -> left);
        in.push_back(root -> val);
        inorder(in, root -> right);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> in;
        inorder(in, root);
        long long sum = 0;
        for(int i = 0; i < in.size(); i++){
            if(in[i] >= low && in[i] <= high){
                sum += in[i];
            }
        }
        return sum;
    }
};