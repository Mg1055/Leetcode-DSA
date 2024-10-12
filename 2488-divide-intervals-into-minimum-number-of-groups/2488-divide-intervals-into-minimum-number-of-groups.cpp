class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        if(intervals.size() == 1)   return 1;

        int minele = INT_MAX, maxele = INT_MIN;
        for(auto p : intervals){
            minele = min(minele, p[0]);
            maxele = max(maxele, p[1]);
        }

        int new_v_size = maxele - minele + 2;
        vector<int>nums(1000005, 0);

        sort(intervals.begin(), intervals.end());
        for(auto p : intervals){
            int l = p[0] - minele;
            int r = p[1] - minele;
            nums[l]++;
            nums[r+1]--;
        }

        int ans = nums[0];
        for(int i = 1; i < new_v_size; i++){
            nums[i] += nums[i-1];
            ans = max(ans, nums[i]);
        }

        return ans;
    }
};