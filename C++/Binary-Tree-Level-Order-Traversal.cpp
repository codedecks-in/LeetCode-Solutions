/*
Problem:
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []
 
Constraints:
The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/


/*
Space Complexity : O(N)
Time Complexity : O(N)
Difficulty level : Medium
*/

class Solution {
public:
	void fun( map<int,vector<int>>&mp, TreeNode* root, int level)
{
    if(!root)
        return;
    
    mp[level].push_back(root->val);
    
    fun(mp,root->left,level+1);
    fun(mp,root->right,level+1);
    
}

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>v;
        if(!root)
            return v;
        
        map<int,vector<int>>mp;
        int level=0;
        fun(mp,root,level);
        auto it=mp.begin();
        while(it!=mp.end())
        {
            v.push_back(it->second);  
            it++;
        }
        
        return v;
        
    }
};
