class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)  return 0;
        unordered_set<int>us(nums.begin(),nums.end());
        
        int ans = 1;
        for(auto x : us){
            if(us.find(x-1) == us.end()){
                int next = x+1;
                int curr_length = 1;
                while(us.find(next) != us.end()){
                    next++;
                    curr_length++;
                }
                ans = max(ans, curr_length);
            }
        }

        return ans;
    }
};