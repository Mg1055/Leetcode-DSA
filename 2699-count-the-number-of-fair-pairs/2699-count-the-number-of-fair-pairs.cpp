class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        while(l <= r){
            int sum = nums[l] + nums[r];
            if(sum < lower){
                l++;
            }
            else if(sum > upper){
                r--;
            }
            else{
                int k1 = upper - nums[r];
                auto it = upper_bound(nums.begin()+l, nums.begin()+r, k1);
                int n1 = (--it) - nums.begin() - l + 1;
                ans += n1;
                cout << "l :" << l << " r: " << r << " ans: " << ans << endl; 

                int k2 = lower - nums[l];
                it = lower_bound(nums.begin()+l+1, nums.begin()+r+1, k2);
                int n2 = r - (it - nums.begin()) + 1;
                ans += n2;
                cout << "l :" << l << " r: " << r << " ans: " << ans << endl; 

                if(n1 > 0 && n2 > 0)
                    ans--;
                l++;
                r--;
            }
        }
        return ans;
    }
};