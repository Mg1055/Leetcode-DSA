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
    bool isCousins(TreeNode* root, int x, int y) {
        if(x == root->val || y == root->val)    return false;
        queue<pair<TreeNode*,int>>q;
        q.push({root, 0});
        int x_parent = -1, x_depth = 0;
        int y_parent = -1, y_depth = 0;
        int depth = 0; 
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front().first;
                int curr_parent = q.front().second;
                q.pop();
                if(curr->val == x){
                    x_depth = depth;
                    x_parent = curr_parent;
                }
                if(curr->val == y){
                    y_depth = depth;
                    y_parent = curr_parent;
                }
                if(x_parent != -1 && y_parent != -1)
                    break;
                if(curr->left != NULL)  q.push({curr->left, curr->val});
                if(curr->right != NULL)  q.push({curr->right, curr->val});
            }
        }

        if(x_depth == y_depth && x_parent != y_parent)
            return true;
        return false;
    }
};