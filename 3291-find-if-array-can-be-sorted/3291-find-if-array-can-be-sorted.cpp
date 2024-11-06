class Solution {
public:

    int setBits(int n){
        int k = 0;
        while(n > 0){
            n = n & n-1;
            k++;
        }
        return k;
    }

    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            bool swapped = false;
            for(int j = 0; j < n-i-1; j++){
                if(nums[j] > nums[j+1]){
                    if(setBits(nums[j]) == setBits(nums[j+1])){
                        swapped = true;
                        swap(nums[j], nums[j+1]);
                    }
                    else{
                        return false;
                    }
                }
            }
            if(swapped == false)
                break;
        }
        
        return true;
    }
};