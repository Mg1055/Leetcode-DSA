class Solution {
public:

    int largestHisto(vector<int>& heights){
        int n = heights.size();
        stack<int>st;

        int maxArea = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = (st.empty()) ? -1 : st.top();
                int currArea = height * (nse - pse - 1);
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int>arr(n,0);

        int largestArea = 0;
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                if(matrix[r][c] == '1')
                    arr[c]++;
                else
                    arr[c] = 0;
            }
            int currArea = largestHisto(arr);
            largestArea = max(currArea, largestArea);
        }
        return largestArea;
    }
};