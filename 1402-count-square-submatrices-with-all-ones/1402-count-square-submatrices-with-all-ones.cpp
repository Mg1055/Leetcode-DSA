class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int r = matrix.size(), c = matrix[0].size();
        vector<int>prev(c+1, 0);

        int ans = 0;
        for(int i = 0; i < r; i++){

            vector<int>curr(c+1,0);
            for(int j = 0; j < c; j++){
                if(matrix[i][j] != 0){
                    curr[j+1] = 1 + min({prev[j], prev[j+1], curr[j]});
                    ans += curr[j+1];
                }
            }
            prev = curr;
        }

        return ans;
    }
};