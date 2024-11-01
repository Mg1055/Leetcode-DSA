class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxInd = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(maxInd < i)  return false;
            maxInd = max(maxInd, i + nums[i]);
            if(maxInd > n)  return true;
        }
        return true;
    }
};