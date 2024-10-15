class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        // int zeroes = 0;
        // int ones = 0;
        int n = s.size();
        int l = 0, r = 0;
        for(;r < n; r++){
            if(s[r] == '0')
                ans += r-(l++);
        }
        return ans;
    }
};