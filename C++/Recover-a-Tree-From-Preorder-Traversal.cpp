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
    TreeNode* recoverFromPreorder(string s) {
        int i = 0;
        int n = s.size();
        
        vector<pair<int, int>> vp;
        while (i < n) {
            int cnt = 0;
            while (i < n && s[i] == '-') {
                ++cnt;
                ++i;
            }
            
            string num;
            while (i < n && '0' <= s[i] && s[i] <= '9') {
                num += s[i];
                ++i;
            }
            
            int m = stoi(num);
            
            vp.push_back({cnt, m});
        }
        
        map<int, pair<int, TreeNode*>> last;
        
        TreeNode * result = new TreeNode(vp[0].second);
        
        last[vp[0].first] = {0, result};
        
        for (int i = 1; i < vp.size(); ++i) {
            if (last[vp[i].first - 1].first == 0) {
                last[vp[i].first - 1].second->left = new TreeNode(vp[i].second);
                last[vp[i].first - 1].first = 1;
                last[vp[i].first] = {0, last[vp[i].first - 1].second->left};
            } else {
                last[vp[i].first - 1].second->right = new TreeNode(vp[i].second);
                last[vp[i].first - 1].first = 2;
                last[vp[i].first] = {0, last[vp[i].first - 1].second->right};
            }
        }
        
        return result;
    }
};