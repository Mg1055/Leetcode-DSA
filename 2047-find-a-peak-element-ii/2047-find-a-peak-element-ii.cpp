class Solution {
public:

    int findMaxEleIdx(vector<vector<int>>& mat, int n, int m, int col){
        int maxVal = -1, idx = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxVal){
                maxVal = mat[i][col];
                idx = i;
            }
        }
        return idx;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        int low = 0, high = m-1;
        while(low <= high){
            int mid = (low + high)/2;
            int maxEleIdx = findMaxEleIdx(mat, n, m, mid);
            int left = mid-1 >= 0 ? mat[maxEleIdx][mid-1] : -1;
            int right = mid + 1 < m ?  mat[maxEleIdx][mid+1] : -1;
            if(mat[maxEleIdx][mid] > left && mat[maxEleIdx][mid] > right)
                return {maxEleIdx, mid};
            else if(mat[maxEleIdx][mid] < left)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1,-1};
    }
};