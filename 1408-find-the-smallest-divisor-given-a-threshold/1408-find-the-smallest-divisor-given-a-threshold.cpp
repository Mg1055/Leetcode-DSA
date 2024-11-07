class Solution {
public:

    bool isPossible(vector<int>&nums, int t, int div){
        int n = nums.size();
        int cnt = 0;
        for(int i = 0; i < n; i++){
            cnt += nums[i]/div;
            if(nums[i]%div != 0)
                cnt++; 
        }
        return cnt <= t;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();

        int  l = 1, r = INT_MIN;
        for(auto x : nums)
            r = max(r, x);

        while(l <= r){
            int mid = (l+r)/2;
            if(isPossible(nums, threshold, mid))
                r = mid-1;
            else 
                l = mid+1;
        }

        return l;
    }
};