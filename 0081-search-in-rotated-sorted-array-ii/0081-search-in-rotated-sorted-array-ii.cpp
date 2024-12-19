class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l <= r){
            int mid = (l+r)/2;
            if(nums[mid] ==  target){
                return true;
            }
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid])){  
                // [3(l), 1, 2, 3(mid), 3, 3, 3(r)] only condition that creates a problem as compared to when there are only distinct elements
                l++;
                r--;
            }
            else if(nums[mid] >= nums[l]){
                if(nums[mid] >= target && nums[l] <= target)
                    r = mid-1;
                else
                    l = mid+1;
            }
            else{
                if(nums[mid] <= target && nums[r] >= target)
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return false;
    }
};