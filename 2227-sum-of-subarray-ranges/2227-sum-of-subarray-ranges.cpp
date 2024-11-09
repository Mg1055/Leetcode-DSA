class Solution {
public:

    void findNSE(vector<int>& nums, vector<int>&nse, int n) {
        stack<int> st;
        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPSEE(vector<int>& nums, vector<int>& psee, int n) {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            psee[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    long long sumSubarrayMins(vector<int>& nums, int n) {
        vector<int> nse(n);
        findNSE(nums, nse, n);
        vector<int> psee(n);
        findPSEE(nums, psee, n);

        long long total = 0;
        for(int i = 0; i < nums.size(); i++) {
            int left = i - psee[i];
            int right = nse[i] - i;

            total += right * left * 1LL * nums[i];
        }
        return total;
    }

    void findNGEE(vector<int>& nums, vector<int>& ngee, int n) {
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            ngee[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    void findPGE(vector<int>& nums, vector<int>& pge, int n) {
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            pge[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }

    long long sumSubarrayMax(vector<int>& nums, int n) {
        vector<int> ngee(n);
        findNGEE(nums, ngee, n);
        vector<int> pge(n);
        findPGE(nums, pge, n);

        long long total = 0;
        for (int i = 0; i < n; i++) {
            int left = i - pge[i];
            int right = ngee[i] - i;
            
            total += right * left * 1LL * nums[i];
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long maxSum = sumSubarrayMax(nums, n);
        long long minSum = sumSubarrayMins(nums, n);
        return maxSum - minSum;
    }
};