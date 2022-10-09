/*
Solution summary:
At first build an array or vector with inorder traverse
Then check that is it increasing order or not
 */
class Solution {
public:
    vector<int>v;
    /// inorder traverser
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        /// check it is increasing order
        for(int i=1; i<v.size(); i++){
            if(v[i]<=v[i-1]) return false;
        }
        return true;
    }
};
/*
Accepted
Your input: [2,1,3]
Output: true
Expected: true
*/
/*
Difficulty level: Medium
Time complexity: O(n)
Space Complexity: O(n)
 */