class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[i] >= arr[st.top()])
                st.pop();
            if(!st.empty())
                ans[i] = st.top()-i;
            st.push(i);
        }
        return ans;
    }
};