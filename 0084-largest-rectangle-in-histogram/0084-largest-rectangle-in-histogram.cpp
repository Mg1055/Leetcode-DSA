class Solution {
public:

    void findNSE(vector<int>&arr, vector<int>&nse, int n){
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        
    }

    void findPSE(vector<int>&arr, vector<int>&pse, int n){
        stack<int>st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            pse[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>nse(n);
        vector<int>pse(n);
        findNSE(heights, nse, n);
        findPSE(heights, pse, n);

        int maxArea = 0;
        for(int i = 0; i < n; i++)
            maxArea = max(maxArea, heights[i]*(nse[i] - pse[i] - 1));
        return maxArea;
    }
};