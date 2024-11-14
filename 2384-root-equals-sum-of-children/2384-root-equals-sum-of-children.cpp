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
    bool checkTree(TreeNode* root) {
        if(root == NULL)    return true;
        if(root->left == NULL && root->right == NULL)   return true;
        int lsum = (root->left == NULL) ? 0 : root->left->val;
        int rsum = (root->right == NULL) ? 0 : root->right->val;
        if(root->val != lsum + rsum)    return false;
        return checkTree(root->left) && checkTree(root->right);
    }
};