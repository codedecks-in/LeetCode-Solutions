#include <iostream>
#include <queue>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;

    queue<TreeNode*> q;

    // Push left and right children of root
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
        TreeNode *leftNode=q.front();
        q.pop();
        TreeNode *rightNode=q.front();
        q.pop();
        if(leftNode==NULL && rightNode!=NULL) {
            return false;
        }
        else if(leftNode!=NULL && rightNode==NULL) {
            return false;
        }
        else if(leftNode!=NULL && rightNode!=NULL) {
            if(leftNode->val!=rightNode->val) {
                return false;
            }
        }
        if(leftNode->left!=NULL) {
            q.push(leftNode->left);
        }
        if(rightNode->right!=NULL) {
            q.push(rightNode->right);
        }
        if(leftNode->right!=NULL) {
            q.push(leftNode->right);
        }
        if(rightNode->left!=NULL) {
            q.push(rightNode->left);
        }
    }

    return true;
}

int main() {
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right=new TreeNode(4);
    root->right=new TreeNode(2);
    root->right->left=new TreeNode(4);
    root->right->right=new TreeNode(3);

    cout << isSymmetric(root);
    return 0;
}