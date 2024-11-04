class Solution {
public:

    vector<vector<string>>ans;

    bool is_Valid(vector<string> &board, int r, int c){
        int n = board.size();
        for(int i = 0; i < r; i++){
            if(board[i][c] == 'Q')
                return false;
        }
        for(int i = r-1, j = c-1; i >= 0 && j >= 0; i--, j--){
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = r-1, j = c+1; i >= 0 && j < n; i--, j++){
            if(board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    
    void solve(vector<string>& board, int row){
        int n = board.size();
        if(row == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col < n; col++){
            if(is_Valid(board, row, col) == true){
                board[row][col] = 'Q';
                solve(board, row+1);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n, string(n,'.'));
        solve(board, 0);
        return ans;        
    }
};