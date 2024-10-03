class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long totalSum = 0;
        for (int num : nums)
            totalSum += num;
        
        int rem = totalSum % p;
        if (rem == 0) return 0;

        unordered_map<int, int> um;
        um[0] = -1;
        long prefixSum = 0;
        int minLength = nums.size();

        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            int currentMod = prefixSum % p;
            int targetMod = (currentMod - rem + p) % p;

            if (um.find(targetMod) != um.end()) {
                minLength = min(minLength, i - um[targetMod]);
            }

            um[currentMod] = i;
        }

        return minLength == nums.size() ? -1 : minLength;
    }
};