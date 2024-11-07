class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int n = nums.size();
        for(auto x : nums){
            if(x <= k)
                k++;
            else
                break;
        }
        
        return k;
    }
};