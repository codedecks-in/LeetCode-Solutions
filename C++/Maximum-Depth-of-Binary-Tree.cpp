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
    int maxDepth(TreeNode* root) {
        
        //breadth first search
        
        if (root == nullptr) {
            
            return 0;
            
        }
        
        int count = 0;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        while (!treeQueue.empty()) {
            
            count++;
            
            for (int i = 0; i < treeQueue.size(); i++) {
                
                TreeNode* frontNode = treeQueue.front();
                treeQueue.pop();
                
                if (frontNode->left != nullptr) {
                    
                    treeQueue.push(frontNode->left);
                    
                    
                }
                
                if (frontNode->right != nullptr) {
                    
                    treeQueue.push(frontNode->right);
                                        
                }
                              
                
                
            }
                      
            
        }
        
        return count;
        
    }
};