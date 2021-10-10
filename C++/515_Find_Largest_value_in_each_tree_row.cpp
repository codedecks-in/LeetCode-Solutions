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
// TC -O(N) N-> Number of nodes in a tree
// SC -O(W)We W-> maximum number of nodes possible at one time in queue
// so basically the number of nodes maximum in a row.
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
     vector<int> ans;
        if(root==NULL) return ans;
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->val);
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            int n=q.size();
            int maximum_val= INT_MIN;
            while(n--)
            {
                TreeNode *curr =q.front();
                q.pop();
                if(maximum_val < curr->val)
                    maximum_val=curr->val;
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            ans.push_back(maximum_val);
        }
        return ans;
    }
};