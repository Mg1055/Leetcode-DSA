class Solution {
public:
    
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
    
    void solve(vector<vector<string>> &ans, vector<string> &board, int r){
        int n = board.size();
        if(r == n){
            ans.push_back(board);
            return;
        }
        for(int c = 0; c < n; c++){
            if(is_Valid(board,r,c) == true){
                board[r][c] = 'Q';
                solve(ans,board,r+1);
                board[r][c] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        solve(ans,board,0);
        return ans;
    }
    
};