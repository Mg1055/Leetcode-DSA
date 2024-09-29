class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minEle = INT_MAX, ans = -1;
        for(int i = 0; i < nums.size(); i++){
            minEle = min(minEle, nums[i]);
            ans = max(ans, nums[i] - minEle);
        }
        return ans == 0 ? -1 : ans;
    }
};