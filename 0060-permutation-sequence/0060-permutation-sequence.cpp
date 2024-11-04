class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>nums;
        for(int i = 1; i < n; i++){
            fact *= i;
            nums.push_back(i);
        }
        nums.push_back(n);
        string ans = "";
        k--;
        while(true){
            int new_seq_no = k/fact;
            ans += to_string(nums[new_seq_no]);
            nums.erase(nums.begin() + new_seq_no);
            if(nums.size() == 0)
                break;
            k %= fact; // new position of k
            fact /= nums.size();
        }
        return ans;
    }
};