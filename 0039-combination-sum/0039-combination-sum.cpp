class Solution {
public:

    void f(int i, vector<int>& arr, vector<vector<int>>& ans, vector<int>&temp, int curr_sum, int n, int target){
        if(i == n){
            if(curr_sum == target)
                ans.push_back(temp);
            return;    
        }
        if(curr_sum == target){
            ans.push_back(temp);
            return;
        }
        if(curr_sum > target)
            return;

        curr_sum += arr[i];
        temp.push_back(arr[i]);
        f(i, arr, ans, temp, curr_sum, n, target);


        curr_sum -= arr[i];
        temp.pop_back();
        f(i+1, arr, ans, temp, curr_sum, n, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = candidates.size();
        f(0, candidates, ans, temp, 0, n, target);
        return ans;
    }
};