class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;
        long long ans = 0, s = 0, i = 0;
        
        for(int j = 0; j < nums.size(); j++) {
            mp[nums[j]]++;
            s += nums[j];
            if(k == j - i + 1) {
                if(mp.size() == k) 
                    ans = max(ans, s);
                s -= nums[i];
                mp[nums[i]]--;
                if(!mp[nums[i]]) 
                    mp.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};