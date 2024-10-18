class Solution {
public:

    void solve(const vector<int> &nums, int idx, int currOR, int maxOR, int &ans){
        if (currOR == maxOR)
            ans++;

        for (int i = idx; i < nums.size(); ++i)
            solve(nums, i + 1, currOR | nums[i], maxOR, ans);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        int n = nums.size();
        for(auto c : nums){
            maxOR = maxOR | c; 
        }

        int ans = 0;
        solve(nums, 0, 0, maxOR, ans);
        return ans;
    }
};