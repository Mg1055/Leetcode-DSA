class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        int power2num = pow(2,n);

        for(int i = 0; i < power2num; i++){

            int curr = i;
            int k = 0;
            vector<int>temp;
            while(curr > 0){
                if(curr%2 != 0){
                    temp.push_back(nums[n - k - 1]);
                }
                curr = curr/2;
                k++;
            }
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
        }

        return ans;
    }
};