class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int mask = (1 << maximumBit) - 1;
        vector<int>ans(n);
        for(int i = 0; i < n; i++){
            mask = mask^nums[i];
            ans[n-i-1] = mask;
        }

        return ans;
    }
};