class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>um;
        sort(nums.begin(), nums.end());
        um[nums[0]] = 1;
        
        int ans = 1;
        for(int i = 1; i < nums.size(); i++){
            int k = (int)sqrt(nums[i]);
            if(k*k != nums[i] || um.find(k) == um.end()){
                um[nums[i]] = 1;
            }
            else{
                um[nums[i]] = um[k] + 1;
                ans = max(ans,um[nums[i]]);
            }
        }

        return (ans >= 2) ? ans : -1; 
    }
};