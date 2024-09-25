class Solution {
public:

    bool isPossible(vector<int>&nums, int k, long long maxpages){
        long long currpages = 0;
        for(int i = 0; i < nums.size(); i++){
            if(currpages > maxpages)    return false;
            else if(nums[i] + currpages <= maxpages){
                currpages += nums[i];
            }
            else{
                k--;
                currpages = nums[i];
                if(k < 1)   return false;
            }
        }
        return true;
    }    


    int splitArray(vector<int>& nums, int k) {
        long long l = 0, r = 0;
        for(auto x : nums){
            r += x;
            l = min((int)l, (int)x);
        }

        long long ans = 0;    
        while(l < r){
            long long mid = l + (r-l)/2;
            if(isPossible(nums, k , mid)){
                ans = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return (int)ans;
    }
};