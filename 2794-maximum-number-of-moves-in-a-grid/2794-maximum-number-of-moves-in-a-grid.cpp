class Solution {
public:
    int n, m;

    int f(int i, int j, int prev, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if (i < 0 || j < 0 || i >= n || j >= m) return 0;
        int curr = grid[i][j];
        if (curr <= prev) return 0;

        if(dp[i][j] != -1)  
            return dp[i][j];
        
        return dp[i][j] = 1 + max({
            f(i-1, j+1, curr, grid, dp),
            f(i, j+1, curr, grid, dp),
            f(i+1, j+1, curr, grid, dp)
        });
    }

    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, f(i, 0, -1, grid, dp));
        return ans - 1;
    }
};


        
