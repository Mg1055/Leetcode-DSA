class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue< vector<int>, vector< vector<int> >, greater< vector<int> > >minh;

        int l = 0, r = INT_MIN;
        for(int i = 0; i < k; i++){
            minh.push({nums[i][0], 0, i});
            r = max(r, nums[i][0]);
        }


        l = minh.top()[0];
        int ans_interval_size = r - l;
        int currL = 0, currR = r;

        while(true){
            int num = minh.top()[0];
            int ind = minh.top()[1];
            int list_no = minh.top()[2];
            if(ind == nums[list_no].size() - 1)
                break;
            
            minh.pop();
            ind++;
            
            minh.push({nums[list_no][ind], ind, list_no});

            currL = minh.top()[0], currR = max(currR, nums[list_no][ind]);
            int curr_interval_size = currR - currL;
            if(curr_interval_size < ans_interval_size){
                l = currL;
                r = currR;
                ans_interval_size = curr_interval_size;
            }
        }

        return {l, r};
    }
};