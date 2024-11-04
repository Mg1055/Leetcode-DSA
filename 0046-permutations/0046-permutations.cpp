class Solution {
public:

    vector<vector<int>>ans;

    void f(int ind, vector<int>&nums){
        if(ind == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = ind; i < nums.size(); i++){
            swap(nums[ind], nums[i]);
            f(ind+1, nums);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        f(0, nums);
        return ans;
    }
};