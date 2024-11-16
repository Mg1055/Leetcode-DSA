class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0;
        int cnt = 1;
        
        for (int r = 0; r < nums.size(); r++) {
            if (r > 0 && nums[r - 1] + 1 == nums[r])
                cnt++;
            
            if (r - l + 1 > k) {
                if (nums[l] + 1 == nums[l + 1])
                    cnt--;
                l++;
            }
            
            if (r - l + 1 == k)
                ans.push_back(cnt == k ? nums[r] : -1);
        }
        
        return ans;
    }
};