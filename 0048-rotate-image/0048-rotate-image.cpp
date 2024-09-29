class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int m = matrix.size(), n = matrix[0].size();
        
        //Transpose
        
        for(int i = 0; i < m; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        
        //Mirror
        for(int i = 0; i < m; i++){
            int l = 0, r = n-1;
            while(l < r){
                swap(matrix[i][l],matrix[i][r]);
                l++;
                r--;
            }
        }
        
    }
};