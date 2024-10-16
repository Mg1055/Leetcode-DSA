class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>chars(128,-1);
        int n = s.size();
        int ans = 0;
        int l = -1;
        
        for(int r = 0; r < n; r++){
            l = max(l, chars[s[r]] + 1);
            ans = max(ans, r - l + 1);
            chars[s[r]] = r;
        }
        return ans;
    }
};