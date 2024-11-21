class Solution {
public:

    // int f(int ind, vector<int>&nums, vector<int>&dp){
    //     if(ind == 0)    return nums[0];
    //     if(ind < 0) return 0;

    //     if(dp[ind] != -1)   return dp[ind];

    //     int pick = nums[ind] + f(ind-2, nums, dp);
    //     int notPick = f(ind-1, nums, dp);

    //     return dp[ind] = max(pick, notPick);
    // }

    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev1 = nums[0], prev2 = 0;

        for(int i = 1; i < n; i++){
            int pick = nums[i];
            if(i > 1)   pick += prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};