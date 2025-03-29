// Question:- Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

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
    void solve(TreeNode* root,int low,int high,int &ans){
        if(!root) return;
        if(root-> val >=low && root->val <=high){ //checking if root value is in range
            ans+=root->val;
            solve(root->left, low, high, ans);  //recursively calling left tree
            solve(root->right, low, high, ans);  //recursively calling right tree
        }
        else if(root->val> high){   //if root value is more than high, then according to BST low values won't be in right tree so search left tree
            solve(root->left, low, high, ans);
        }
        else if(root->val < low){ //if root value is less than low, then according to BST low values won't be in left tree so search right tree
            solve(root->right, low, high, ans);
        }
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        solve(root, low, high, sum);
        return sum;
    }
};

// Test Case 1
// Input root = [10,5,15,3,7,null,18]
// low = 7
// high = 15
// Excepted = 32
// Output = 32


// Test Case 2
// Input root = [10,5,15,3,7,13,18,1,null,6]
// low = 6
// high = 10
// Expected = 23
// Output = 23
