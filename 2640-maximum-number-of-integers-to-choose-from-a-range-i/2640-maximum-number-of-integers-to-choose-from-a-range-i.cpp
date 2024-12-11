class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>banned_set(banned.begin(), banned.end());
        int currSum = 0, nums = 0;
        for(int i = 1; i <= n; i++){
            if(banned_set.find(i) != banned_set.end())
                continue;
            currSum += i;
            if(currSum > maxSum)    break;
            nums++;
        }
        return nums;
    }
};