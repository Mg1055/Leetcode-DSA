class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>ans;
        for(int i = 0; i < intervals.size()-1; i++){
            int l1 = intervals[i][0], r1 = intervals[i][1];
            int l2 = intervals[i+1][0], r2 = intervals[i+1][1];
            if(l2 <= r1){
                ans.push_back({l1, max(r1,r2)});
                i++;
            }
            else{
                ans.push_back({l1,r1});
                ans.push_back({l2,r2});
            }
        }
        return ans;
    }
};