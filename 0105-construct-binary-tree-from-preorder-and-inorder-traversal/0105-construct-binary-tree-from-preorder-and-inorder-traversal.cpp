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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        int rootIdxPreorder = 0;
        return build(preorder, inorder, rootIdxPreorder, 0, inorder.size() - 1, mp);
    }

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int &rootIdxPreorder,
        int left, int right, unordered_map<int,int>& mp){
        
        if(left > right)   return NULL;

        int rootVal = preorder[rootIdxPreorder];
        int rootIdxInorder = mp[rootVal];
        TreeNode* node = new TreeNode(rootVal);
        rootIdxPreorder++;

        if(left == right)  return node;
        node->left = build(preorder, inorder, rootIdxPreorder, left, rootIdxInorder-1, mp);
        node->right = build(preorder, inorder, rootIdxPreorder, rootIdxInorder+1, right, mp);

        return node;
    }
};