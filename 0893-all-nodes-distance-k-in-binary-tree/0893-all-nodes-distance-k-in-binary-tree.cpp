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

    void makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            for(int i = 0; i <cnt; i++){
            TreeNode* node = q.front();
                q.pop();
                if(node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        makeParent(root, parent);

        unordered_map<TreeNode*, bool> visited;
        vector<int> ans;
        solve(target, parent, visited, k, ans);
        
        return ans;
    }

    void solve(TreeNode* target,unordered_map<TreeNode*, TreeNode*> &parent,
                unordered_map<TreeNode*, bool>& visited, int dist, vector<int> &ans){
        if(dist == 0)
            ans.push_back(target->val);
        
        visited[target] = true;
        if(target->left && !visited[target->left])
            solve(target->left, parent, visited, dist - 1, ans);

        if(target->right && !visited[target->right])
            solve(target->right, parent, visited, dist - 1, ans);

        if(parent[target] != NULL && !visited[parent[target]])
            solve(parent[target], parent, visited, dist - 1, ans);
    }
};