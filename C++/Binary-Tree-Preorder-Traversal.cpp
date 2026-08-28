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
//This solution is an interative solution for problem #144 using stack
//Preorder Traversal is root, left, right
//The Space and Time Complexity is O(n)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        //if root == nullptr, return empty vector
        if (root == NULL) {
            return result;
        }
        
        stack<TreeNode*> node_stack;
        node_stack.push(root);
        
        while (!node_stack.empty()) {
            TreeNode* node = node_stack.top(); 
            node_stack.pop(); //pop the top node from the stack
            result.push_back(node->val); //add the value to the result vector
            
            if (node->right) {
                node_stack.push(node->right); //push right child to the stack if it exists
            }
            if (node->left) {
                node_stack.push(node->left); //push left child to the stack if it exists
            }
        }
        
        return result;
    }
};
