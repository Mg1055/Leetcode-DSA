class Solution {
public:

    void dfs(vector<vector<int>>& mat, vector<bool>& visited, int row){
        visited[row] = true;
        for(int col = 0; col < mat.size(); col++){
            if(col != row && mat[row][col] == 1 && !visited[col])
                dfs(mat, visited, col);
        }
    }

    int findCircleNum(vector<vector<int>>& mat) {
        int cnt = 0;
        int n = mat.size();
        vector<bool>visited(n, false);
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++;
                dfs(mat, visited, i);
            }
        }
        return cnt;
    }
};