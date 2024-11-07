class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        // O(n) solution
        
        // int n = nums.size();
        // for(auto x : nums){
        //     if(x <= k)
        //         k++;
        //     else
        //         break;
        // }
        
        // return k;


        // Binary search
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r){
            int mid = (r+l)/2;
            int missing = nums[mid] - (mid+1);

            if(missing < k)
                l = mid+1;
            else
                r = mid-1;
        }

        // need arr[r] + more
        // more = k - missing = k - (arr[r] - (r+1)) = k - arr[r] + r + 1;
        // arr[r] + more = arr[r] + k - arr[r] + r + 1 = r + k + 1
        return r+k+1;
    }
};