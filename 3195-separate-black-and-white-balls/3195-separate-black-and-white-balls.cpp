class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int zeroes = 0;
        int n = s.size();
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '1')
                ans += zeroes;
            else
                zeroes++;
        }
        return ans;
    }
};