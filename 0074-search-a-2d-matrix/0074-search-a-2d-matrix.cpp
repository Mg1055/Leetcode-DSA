class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();

        // search for row first (bs), then search in that row (bs)

        // int row = -1;
        // int l = 0, r = n-1;
        // while(l <= r){
        //     int mid = l + (r-l)/2;
        //     if(matrix[mid][0] == target)    
        //         return true;
        //     else if(matrix[mid][0] > target)
        //         r = mid-1;
        //     else
        //         l = mid+1;
        // }
        // row = r; 
        // if(r >= 0){
        //     l = 0, r = m-1;
        //     while(l <= r){
        //         int mid = l + (r-l)/2;
        //         if(matrix[row][mid] == target)     
        //             return true;
        //         else if(matrix[row][mid] > target)
        //             r = mid-1;
        //         else
        //             l = mid+1;
        //     }
        // }
        // return false;


        // flatten the matrix
        int l = 0, r = n*m - 1;
        while(l <= r){
            int mid = (l+r)/2;
            int row = mid/m, col = mid%m;
            if (matrix[row][col] == target) 
                return true;
            else if (matrix[row][col] < target) 
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return false;
    }
};