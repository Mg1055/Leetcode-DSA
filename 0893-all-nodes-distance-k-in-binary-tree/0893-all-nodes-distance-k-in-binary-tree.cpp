/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void makeParent(TreeNode* root, unordered_map<int, TreeNode*>& parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            for(int i = 0; i <cnt; i++){
            TreeNode* node = q.front();
                q.pop();
                if(node->left) {
                    parent[node->left->val] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right->val] = node;
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> parent;
        makeParent(root, parent);

        unordered_map<int, bool> visited;
        vector<int> ans;
        solve(target, parent, visited, k, ans);
        
        return ans;
    }

    void solve(TreeNode* target,unordered_map<int, TreeNode*> &parent,
                unordered_map<int, bool>& visited, int dist, vector<int> &ans){
        if(dist == 0)
            ans.push_back(target->val);
        
        visited[target->val] = true;
        if(target->left && !visited[target->left->val])
            solve(target->left, parent, visited, dist - 1, ans);

        if(target->right && !visited[target->right->val])
            solve(target->right, parent, visited, dist - 1, ans);

        if(parent[target->val] != NULL && !visited[parent[target->val]->val])
            solve(parent[target->val], parent, visited, dist - 1, ans);
    }
};