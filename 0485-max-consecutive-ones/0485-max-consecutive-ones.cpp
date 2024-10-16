class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones_cnt = 0, ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                ones_cnt++;
            else{
                ans = max(ans, ones_cnt);
                ones_cnt = 0;
            }
        }
        ans = max(ans, ones_cnt);
        return ans;
    }
};