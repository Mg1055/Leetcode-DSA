class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        // int zeroes = 0;
        int ones = 0;
        int n = s.size();
        for(auto c : s){
            if(c == '0')
                ans += ones;
            else
                ones++;
        }
        return ans;
    }
};