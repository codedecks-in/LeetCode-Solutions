//CPP DFS solution 
//Time complexity O(V+E)
//Space Complexity O(V)
class Solution {
public:
    void dfs(vector<vector<int>>&v, vector<int>k,TreeNode*r,int s){
        if(r==NULL){
            return;
        }
        if(s==r->val&&r->left==NULL&&r->right==NULL){
            k.push_back(r->val);
            v.push_back(k);
            //k.clear();
            return;
            
        }
        else if(s!=r->val&&r->left==NULL&&r->right==NULL){
            return;
        }
        
        k.push_back(r->val);
        s-=r->val;
        dfs(v,k,r->left,s);
        dfs(v,k,r->right,s);
            
        
        
        return;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>v;
        vector<int>k;
        dfs(v,k,root,sum);
        return v;
    }
};