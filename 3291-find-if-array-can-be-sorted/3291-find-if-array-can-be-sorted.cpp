class Solution {
public:
    int countSetBits(int n){
        int setBits = 0;
        while(n > 0){
            n = n & n-1;
            setBits++;
        }
        return setBits;
    }

    bool canSortArray(vector<int>& nums) {
        
        int n = nums.size();
        int curr_min = nums[0], curr_max = nums[0];
        int prev_max = INT_MIN;

        for(int i = 0; i < n; i++){
            if(countSetBits(nums[i]) == countSetBits(curr_min)){
                curr_min = min(curr_min, nums[i]);
                curr_max = max(curr_max, nums[i]);
            }
            else{
                if(curr_min < prev_max)
                    return false;
                prev_max = curr_max;
                curr_min = nums[i], curr_max = nums[i];
            }
        }
        
        if(curr_min < prev_max)
            return false;
        return true;

        // bubble sort

        // int n = nums.size();
        
        // for(int i = 0; i < n; i++){
        //     bool swapped = false;
        //     for(int j = 0; j < n-i-1; j++){
        //         if(nums[j] > nums[j+1]){
        //             if(countSetBits(nums[j]) == countSetBits(nums[j+1])){
        //                 swapped = true;
        //                 swap(nums[j], nums[j+1]);
        //             }
        //             else{
        //                 return false;
        //             }
        //         }
        //     }
        //     if(swapped == false)
        //         break;
        // }
        
        // return true;
    }
};