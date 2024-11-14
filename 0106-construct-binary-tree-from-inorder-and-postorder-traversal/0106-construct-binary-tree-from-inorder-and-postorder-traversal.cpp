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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();
        unordered_map<int,int>mp;
        for(int i = 0; i < n; i++)
            mp[inorder[i]] = i;
        int rootIdxPostorder = n-1;
        return build(postorder, inorder, rootIdxPostorder, 0, n - 1, mp);
    }

    TreeNode* build(vector<int>& postorder, vector<int>& inorder, int &rootIdxPostorder,
        int left, int right, unordered_map<int,int>& mp){
        
        if(left > right)   return NULL;

        int rootVal = postorder[rootIdxPostorder];
        int rootIdxInorder = mp[rootVal];
        TreeNode* node = new TreeNode(rootVal);
        rootIdxPostorder--;

        if(left == right)  return node;
        node->right = build(postorder, inorder, rootIdxPostorder, rootIdxInorder+1, right, mp);
        node->left = build(postorder, inorder, rootIdxPostorder, left, rootIdxInorder-1, mp);

        return node;
    }
};