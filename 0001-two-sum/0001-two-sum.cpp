class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // hash map
        // unordered_map<int,int>um;
        // for(int i = 0; i < nums.size(); i++){
        //     if(um.find(target-nums[i]) != um.end())
        //         return {um[target-nums[i]], i};
        //     um[nums[i]] = i;
        // }
        // return {};


        // two pointer
        vector<pair<int,int>>n;
        pair<int,int>p;
        for(int i = 0; i < nums.size(); i++)
            n.push_back({nums[i],i});

        sort(n.begin(),n.end());
        int l = 0, r = nums.size()-1;
        while(l < r){
            int temp = n[l].first + n[r].first;
            if(temp == target)
                return {n[l].second, n[r].second};
            else if(temp > target)
                r--;
            else
                l++;
        }
        return {};
    }
};