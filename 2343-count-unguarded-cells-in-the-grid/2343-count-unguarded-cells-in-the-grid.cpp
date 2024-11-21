class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>matrix(m, vector<int>(n,0));

        vector<int>dir = {0,1,0,-1,0};
        for(auto v : walls)
            matrix[v[0]][v[1]] = 1;

        for(auto v : guards)
            matrix[v[0]][v[1]] = 2;

        for(auto v : guards){
            int row = v[0], col = v[1];
            matrix[row][col] = 2;
            for(int i = 0; i < 4; i++){
                int r = row + dir[i], c = col + dir[i+1];
                while(r >= 0 && c >= 0 && r < m && c < n && matrix[r][c] != 1 && matrix[r][c] != 2){
                    matrix[r][c] = 3;
                    r += dir[i];
                    c += dir[i+1];
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m ; i++){
            for(int j = 0; j < n; j++)
                if(matrix[i][j] == 0)
                    ans++;
        }
        return ans;
    }
};