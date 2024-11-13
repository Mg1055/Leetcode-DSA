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

    int trav(TreeNode* root, int &pathSum){
        if(root == NULL)    return 0;

        int lp = max(0, trav(root->left, pathSum));
        int rp = max(0, trav(root->right, pathSum));
        pathSum = max(pathSum, lp + rp + root->val);

        return root->val + max(lp, rp);
    }

    int maxPathSum(TreeNode* root) {
        int pathSum = INT_MIN;
        trav(root, pathSum);
        return pathSum;
    }
};