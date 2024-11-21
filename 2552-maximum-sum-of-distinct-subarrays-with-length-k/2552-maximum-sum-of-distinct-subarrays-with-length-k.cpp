class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> prev_idx;
        long long curSum = 0;
        
        int l = 0;
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            int i = -1;
            if (prev_idx.find(nums[r]) != prev_idx.end())
                i = prev_idx[nums[r]];
            
            while (l <= i || r - l + 1 > k) {
                curSum -= nums[l];
                l++;
            }
            
            if (r - l + 1 == k)
                res = max(res, curSum);
            
            prev_idx[nums[r]] = r;
        }
        
        return res;
    }
};