class Solution {
public:
    int maximumSwap(int num) {
        vector<int>curr_nums;
        int k = num;
        while(k > 0){
            curr_nums.push_back(k%10);
            k = k/10;
        }
        reverse(curr_nums.begin(), curr_nums.end());

        int n = curr_nums.size();
        vector<pair<int,int>>max_nums(n, make_pair(0, 0));
        
        max_nums[n-1].first = curr_nums[n-1];
        max_nums[n-1].second = n-1;
        for(int i = n-2; i >= 0; i--){
            if(curr_nums[i] > max_nums[i+1].first){
                max_nums[i].first = curr_nums[i];
                max_nums[i].second = i;
            }
            else{
                max_nums[i] = max_nums[i+1];
            }
        }

        for(int i = 0; i < n; i++){
            if(max_nums[i].first > curr_nums[i]){
                int second_ind = max_nums[i].second;
                swap(curr_nums[i], curr_nums[second_ind]);
                break;
            }
        }

        int newNum = 0;
        for(int i = 0; i < n; i++){
            newNum = newNum*10 + curr_nums[i];
        }

        return newNum;
    }
};