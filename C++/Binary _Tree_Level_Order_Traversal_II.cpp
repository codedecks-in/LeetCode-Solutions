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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        if(root == NULL)
            return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
          int size = q.size();
          vector<int>temp;
          for(int i = 0; i <size;i++){
             
            TreeNode* currentNode = q.front();
            q.pop();
            
            temp.push_back(currentNode->val);
            if(currentNode->left)
              q.push(currentNode->left);
            if(currentNode->right)
              q.push(currentNode->right);
          }
          res.push_back(temp);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
