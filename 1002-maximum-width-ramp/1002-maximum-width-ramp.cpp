class Solution {
public:
    int maxWidthRamp(vector<int>& arr) {
        int n = arr.size();
        vector<int>nums(n,0);
        nums[n-1] = arr[n-1];
        for(int i = n-2; i >= 0; i--)
            nums[i] = max(nums[i+1], arr[i]);

        int l = 0, r = 0;
        int ans = 0;
        while(r < n){
            while(l < r && arr[l] > nums[r])
                l++;
            ans = max(ans, r - l);
            r++;
        }

        return ans;
    }
};