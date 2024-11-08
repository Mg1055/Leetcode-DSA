class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>nge(n, -1);
        stack<int>st;
        int i = n-1;
        for(; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
            nge[i] = (st.empty()) ? -1 : st.top();
            st.push(nums[i]);
        }

        i = n-1;
        for(; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
            nge[i] = (st.empty()) ? -1 : st.top();
            st.push(nums[i]);
        }

        return nge;
    }
};