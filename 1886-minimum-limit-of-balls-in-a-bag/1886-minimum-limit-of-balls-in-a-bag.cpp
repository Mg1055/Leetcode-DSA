class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int maxn = INT_MIN;
        for(auto x : nums) 
            maxn = max(maxn, x);
        
        int l = 1, r = maxn;
        while(l <= r){
            int mid = (l+r)/2;
            if(isPossible(nums, maxOperations, mid))
                r = mid-1;
            else
                l = mid+1;
        }
        return l;
    }

    bool isPossible(vector<int>&nums, int maxOperations, int penalty){
        int requiredOperations = 0;
        for(auto n : nums){
            int x = n/penalty;
            if(n % penalty == 0)    x--;
            requiredOperations += x;
        }
        return requiredOperations <= maxOperations;
    }
};