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

// Question link: https://leetcode.com/problems/house-robber-iii/
class Solution
{
public:
    /*
    Why is this DP on tree? And not simply greedy?
    Try to think of some cases, like 5 -> 4 -> 2 -> 3
    here greedy takes only alternate levels sum -> max(5 + 2, 4 + 3)
     and misses the final answer as 5 + 3 (choosing the main root and last leaf) giving 8
    
    Case 1: you choose the current node
    Case 2: you dont choose the current node
    
    Caching using map(unordered because its quicker than std::map & since we dont need nodes sorted in this question), to avoid TLE

    Time Complexity: O(N) (because traversing over all N nodes of tree)
    Space Complexity: O(N)  (because of map)
    */
    unordered_map<TreeNode *, int> mp; // maximum value obtained for this node, stored as pairs in map
    int helper(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (mp.find(root) != mp.end())
            return mp[root];
        int case1 = root->val;
        if (root->left)
        {
            case1 += helper(root->left->left);
            case1 += helper(root->left->right);
        }
        if (root->right)
        {
            case1 += helper(root->right->right);
            case1 += helper(root->right->left);
        }
        int case2 = helper(root->left) + helper(root->right);
        return mp[root] = max(case1, case2);
    }
    int rob(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = helper(root);
        return ans;
    }
};