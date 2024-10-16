class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0)  return 0;

        int l = 0, r = 0;
        vector<int>chars(26,0);
        if(isalpha(s[0]) )
            chars[s[0] - 'a']++;
        
        int ans = 1;
        int curr_length = 1;
        while(r < n-1){
            if(!isalpha(s[r])){
                r++;
                continue;
            }
            r++;
            int curr_char_no = s[r] - 'a';
            while(chars[curr_char_no] != 0){
                if(!isalpha(s[l])){
                    l++;
                    continue;
                }
                chars[s[l] - 'a']--;
                l++;
            }
            ans = max(ans, r - l + 1);
            chars[curr_char_no]++;
        }   

        return ans;
    }
};