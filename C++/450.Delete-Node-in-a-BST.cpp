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
/*

Time Complexity:
Average case: O(log(n))
Worst case: O(n)

Space Complexity:
Average case: O(log(n))
Worst case: O(n)
*/
class Solution {
public:

    // Find the minimum value in the right subtree
    int minVal(TreeNode* &root)
    {
        TreeNode* temp = root;

        // Move to the leftmost node
        while(temp->left != NULL)
        {
            temp = temp->left;
        }

        return temp->val;
    }

    // Delete a node with the given key
    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root == NULL)
        {
            return root; // Base case: empty tree
        }
        
        if(root->val == key)
        {
            // Case 1: Node has 0 children
            if(root->left == NULL && root->right == NULL)
            {
                delete root;
                return NULL;
            }

            // Case 2: Node has 1 child (left)
            if(root->left != NULL && root->right == NULL)
            {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 2: Node has 1 child (right)
            if(root->left == NULL && root->right != NULL)
            {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // Case 3: Node has 2 children
            if(root->left != NULL && root->right != NULL)
            {
                int mini = minVal(root->right); // Find smallest value in right subtree
                root->val = mini; // Replace value with smallest value
                root->right = deleteNode(root->right , mini); // Delete the duplicate node
                return root;
            }
        }

        // Recur to the left or right subtree based on key comparison
        if(root->val >= key)
        {
            root->left = deleteNode(root->left , key);
        }
        else
        {
            root->right = deleteNode(root->right , key);
        }

        return root;
    }
};
