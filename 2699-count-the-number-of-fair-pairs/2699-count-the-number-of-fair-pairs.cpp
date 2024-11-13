class Solution {
public:

    long long countLess(vector<int>& nums, int val) {
        long long ans = 0;
        for(int i = 0, j = nums.size() - 1; i < j; i++){
            while(i < j && nums[i] + nums[j] >= val)
                j--;
            ans += j - i;
        }        
        return ans;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countLess(nums, upper+1) - countLess(nums, lower);
    }
};