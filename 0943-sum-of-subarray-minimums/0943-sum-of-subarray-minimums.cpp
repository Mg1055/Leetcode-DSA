class Solution {
public:
    int mod = 1e9+7;
    void prev_smaller_equal_element_index(vector<int>& arr, int n, vector<int>& ans){
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) 
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void next_smaller_element_index(vector<int>& arr, int n, vector<int>& ans){
        stack<int> st;
        for(int i = n-1 ; i >= 0 ; i--){
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> prev(n), next(n);
        prev_smaller_equal_element_index(arr, n, prev);
        next_smaller_element_index(arr, n, next); 
        long long sum = 0 ; 
        for(int i = 0; i < arr.size(); i++){
            long long left = i - prev[i];
            long long right = next[i] - i;
            sum = (sum + (left*right*arr[i]) % mod) % mod;
        }
        return sum;
    }
};