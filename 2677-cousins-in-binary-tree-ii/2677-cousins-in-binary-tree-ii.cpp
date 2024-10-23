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
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        root->val = 0;
        
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*>level_nodes;
            int curr_sum = 0;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); 
                q.pop();
                level_nodes.push_back(curr);
                if(curr->left){  
                    q.push(curr->left);
                    curr_sum += curr->left->val;
                }
                if(curr->right){
                    q.push(curr->right);
                    curr_sum += curr->right->val;
                }
            }

            for(auto node : level_nodes){
                int k = curr_sum;
                if(node->left)  k -= node->left->val;
                if(node->right) k -= node->right->val;
                if(node->left)  node->left->val = k;
                if(node->right) node->right->val = k;
            }
        }

        return root;
    }
};