/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> finalvec;
        int flag = 1;
        TreeNode *t;
        stack<TreeNode*>s1;
        stack<TreeNode*>s2;
        if(root==NULL)
            return finalvec;
        s1.push(root);
        // vector<int>temp;
        // temp.push_back(root->val);
        // finalvec.push_back(temp);
        while(!s1.empty() || !s2.empty())
        {
            if(flag == 1)
            {
                vector<int>temp;
                while(!s1.empty())
                {
                    t = s1.top();
                    s1.pop();
                    temp.push_back(t->val);
                    if(t->left)
                        s2.push(t->left);
                    if(t->right)
                        s2.push(t->right);
                    
                }
                finalvec.push_back(temp);
                flag = 0;
            }
            else
            {
                vector<int>temp;
                while(!s2.empty())
                {
                    t = s2.top();
                    s2.pop();
                    temp.push_back(t->val);
                    if(t->right)
                        s1.push(t->right);
                    if(t->left)
                        s1.push(t->left);
                    
                }
                 finalvec.push_back(temp);
                 flag = 1;
            }
        }
        
        return finalvec;
    }
};
