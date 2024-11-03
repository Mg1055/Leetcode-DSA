class Solution {
public:
    vector<vector<int>>ans;

    void f(int ind, int t, vector<int>&arr, vector<int>&temp){
        if(t == 0){
            ans.push_back(temp);
            return;
        }
        if(ind == arr.size()){
            if(t == 0)
                ans.push_back(temp);
            return;
        }

        if(t - arr[ind] >= 0){
            temp.push_back(arr[ind]);
            f(ind, t - arr[ind], arr, temp);
            temp.pop_back();
        }
        f(ind+1, t, arr, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int>temp;
        f(0, target, candidates, temp);
        return ans;
    }
};