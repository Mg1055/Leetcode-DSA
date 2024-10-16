class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios::sync_with_stdio(0);cin.tie(0);
        int n = nums.size();
        if(n == 0)  return 0;
        unordered_set<int>us(nums.begin(),nums.end());
        int ans = 1;
        for(auto x : nums){
            if(us.find(x-1) == us.end()){
                int cnt = 1, next = x+1;
                while(us.find(next) != us.end()){
                    cnt++;
                    next++;
                }
                ans = max(cnt,ans);
            }
        }
        return ans;
    }
};