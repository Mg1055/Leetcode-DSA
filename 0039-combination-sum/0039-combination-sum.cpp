class Solution {
public:

    void f(int i, vector<int>& arr, vector<vector<int>>& ans, vector<int>&temp, int target){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        if(i == arr.size()){
            if(target == 0)
                ans.push_back(temp);
            return;
        }

        if(arr[i] <= target){
            temp.push_back(arr[i]);
            f(i, arr, ans, temp, target - arr[i]);
            temp.pop_back();
        }
        f(i+1, arr, ans, temp, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = candidates.size();
        f(0, candidates, ans, temp, target);
        return ans;
    }
};