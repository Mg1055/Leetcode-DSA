class Solution {
public:


    int rob1(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int prev1 = nums[l], prev2 = 0;

        for(int i = l+1; i <= r; i++){
            int pick = nums[i];
            if(i > 1)   pick += prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)  return nums[0];     
        return max(rob1(nums, 0, n-2) , rob1(nums, 1, n-1));
    }
};