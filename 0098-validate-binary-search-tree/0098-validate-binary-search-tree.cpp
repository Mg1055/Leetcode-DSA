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
    
    bool isValidBST(TreeNode* root) {
        return isValid(root, LONG_MIN, LONG_MAX);
    }

    bool isValid(TreeNode* root, long minVal, long maxVal) {
        if(root == NULL) return true;
        if(minVal > root->val || root->val > maxVal)
            return false;
        long currVal = (long)root->val;
        return isValid(root->left, minVal, currVal-1) 
            && isValid(root->right, currVal+1, maxVal);
    }
};