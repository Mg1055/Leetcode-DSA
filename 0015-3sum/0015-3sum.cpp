class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        if(n < 3)     
            return ans;
        if(nums[0] > 0)     
            return ans;
    
        for(int i = 0; i < n-2; i++){
            if(nums[i] > 0) 
                break;
            if(i == 0 || (i > 0 && nums[i] != nums[i-1])){
                int l = i+1, r = n-1, sum = -nums[i];
                while(l < r){
                    if(nums[l] + nums[r] == sum){
                        ans.push_back({nums[i],nums[l],nums[r]});
                        while( l < r && nums[l] == nums[l+1])   l++;
                        while( l < r && nums[r] == nums[r-1])   r--;
                        l++;r--;
                    }
                    else if(nums[l] + nums[r] < sum)
                        l++;
                    else
                        r--;
                }
            }
        }
        return ans;
    }
};