class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ele = nums[0], cnt = 1, n = nums.size();
        for(int i = 1; i < n; i++){
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
            else{
                if(nums[i] == ele)
                    cnt++;
                else
                    cnt--;
            }
        }

        return ele;
    }
};