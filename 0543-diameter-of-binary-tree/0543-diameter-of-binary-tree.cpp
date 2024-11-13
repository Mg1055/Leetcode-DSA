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
    int ans;

    int trav(TreeNode* root){
        if(root == NULL)    return 0;

        int lh = trav(root->left);
        int rh = trav(root->right);
        int dist = lh + rh;
        cout << "dist: " << dist << endl;
        ans = max(ans, dist);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        trav(root);
        return ans;
    }
};