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
    int cnt=0;
public:
    void inorder(TreeNode* root){
        if(root==NULL)
            return;
        inorder(root->left);
        cnt++;
        inorder(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL)
            return 0;
       inorder(root);
        return cnt;
    }
};
