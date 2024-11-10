class Solution {
public:

    void addToWindow(vector<int>& bits, int x){
        for(int i = 0; i < 32; i++){
            if(x & (1 << i))
                bits[i]++;
        }
    }

    void removeFromWindow(vector<int>& bits, int x){
        for(int i = 0; i < 32; i++){
            if(x & (1 << i))
                bits[i]--;
        }
    }

    int bitsArraytoNum(vector<int>&bits){
        int ans = 0;
        for(int i = 0; i < 32; i++){
            if(bits[i])
                ans |= 1 << i;
        }
        return ans;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<int>bits(32,0);
        int l = 0, r;
        for(r = 0; r < n; r++){
            addToWindow(bits, nums[r]);
            while(l <= r && bitsArraytoNum(bits) >= k){
                ans = min(ans, r-l+1);
                removeFromWindow(bits, nums[l++]);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};