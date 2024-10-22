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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>maxh;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int cnt = q.size();
            long long curr_sum = 0;
            for(int i = 0; i < cnt; i++){
                TreeNode* curr = q.front();
                q.pop();
                curr_sum += curr->val;
                if(curr->left != NULL)  q.push(curr->left);
                if(curr->right != NULL)  q.push(curr->right);
            }
            maxh.push(curr_sum);
            if(maxh.size() > k) maxh.pop();
        }

        if(maxh.size() < k) return -1;
        return (long long)maxh.top();
    }
};