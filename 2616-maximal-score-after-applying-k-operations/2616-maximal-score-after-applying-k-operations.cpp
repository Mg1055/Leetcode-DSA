class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        make_heap(nums.begin(), nums.end());
        for(int i = 0; i < k; i++){
            pop_heap(nums.begin(), nums.end());
            int x = nums.back();
            ans += x;
            if(x == 1){
                ans += (k-1-i);
                break;
            }
            nums.back() = (x + 2)/3;
            push_heap(nums.begin(), nums.end());
        }
        return ans;
    }
};