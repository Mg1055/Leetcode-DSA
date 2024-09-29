class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = nums[0], ans = nums[0], n = nums.size();
        for(int i = 1; i < n; i++){
            currsum = max(currsum + nums[i], nums[i]);
            ans = max(currsum, ans);
        }   

        return ans;
    }
};