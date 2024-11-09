class Solution {
public:

    // void findNSE(vector<int>&arr, vector<int>&nse, int n){
    //     stack<int>st;
    //     for(int i = n-1; i >= 0; i--){
    //         while(!st.empty() && arr[st.top()] >= arr[i])
    //             st.pop();
    //         nse[i] = (st.empty()) ? n : st.top();
    //         st.push(i);
    //     }
        
    // }

    // void findPSE(vector<int>&arr, vector<int>&pse, int n){
    //     stack<int>st;
    //     for(int i = 0; i < n; i++){
    //         while(!st.empty() && arr[st.top()] >= arr[i])
    //             st.pop();
    //         pse[i] = (st.empty()) ? -1 : st.top();
    //         st.push(i);
    //     }
    // }

    int largestRectangleArea(vector<int>& heights) {

        // finding area using both nse and pse 

        // int n = heights.size();
        // vector<int>nse(n);
        // vector<int>pse(n);
        // findNSE(heights, nse, n);
        // findPSE(heights, pse, n);

        // int maxArea = 0;
        // for(int i = 0; i < n; i++)
        //     maxArea = max(maxArea, heights[i]*(nse[i] - pse[i] - 1));
        // return maxArea;

        // finding pse and nse on the fly
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
};