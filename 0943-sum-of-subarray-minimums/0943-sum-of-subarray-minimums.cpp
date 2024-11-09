class Solution {
public:
    int mod = 1e9+7;
    void findPSEE(vector<int>& arr, int n, vector<int>& ans){
        stack<int> st;
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && arr[st.top()] > arr[i]) 
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    void findNSE(vector<int>& arr, int n, vector<int>& ans){
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
        vector<int> psee(n), nse(n);
        findPSEE(arr, n, psee);
        findNSE(arr, n, nse); 
        long long sum = 0 ; 
        for(int i = 0; i < arr.size(); i++){
            long long left = i - psee[i];
            long long right = nse[i] - i;
            sum = (sum + (left*right*arr[i]) % mod) % mod;
        }
        return sum;
    }
};