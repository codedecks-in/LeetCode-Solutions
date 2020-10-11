//Author: Vinayak Kokane
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> verticalOrder(Node *root)
  {
    queue< pair<Node*,int> > q;
    q.push(make_pair(root,0));      //horizontal distance of root => 0
    map<int,vector<int>> m;         //map to store the hd and its respective nodes
    vector <int> v;
    while(!q.empty())
    {
        pair <Node*,int> p = q.front();
        q.pop();
        Node* temp = p.first;
        int hd = p.second;
        m[hd].push_back(temp->data);
        
        if(temp->left)
            q.push(make_pair(temp->left,hd-1));
        if(temp->right)
            q.push(make_pair(temp->right,hd+1));
    }
    
    map<int,vector<int>>::iterator it;
    for(it=m.begin(); it!=m.end(); it++)
    {
        for (int i=0; i<it->second.size(); ++i)
        {
            v.push_back(it->second[i]);
        }
    }
    return v;
  }
}
