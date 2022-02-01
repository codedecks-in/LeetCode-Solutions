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
        
        //check base root case
        if (root == nullptr) {
            
            return 0;
            
        }
        
        //initialize return variable and data structure 
        //to store nodes to be checked
        int count = 0;
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        //while loop that will traverse each node in the queue
        while (!treeQueue.empty()) {
            
            //depth variable that will be incremented as
            //the levels are traversed
            count++;
            
            //for loop that is used to check the nodes of the queue
            for (int i = 0; i < treeQueue.size(); i++) {
                
                TreeNode* frontNode = treeQueue.front();
                treeQueue.pop();
                

                //add the left child to the queue            
                if (frontNode->left != nullptr) {
                    
                    treeQueue.push(frontNode->left);
                    
                    
                }
                
                //add the right child to the queue
                if (frontNode->right != nullptr) {
                    
                    treeQueue.push(frontNode->right);
                                        
                }
                              
                
                
            }
                      
            
        }
        
        return count;
        
    }
};