class Solution {
public:

    int takeCharacters(string s, int k) {
        vector<int>cnts(3,0);
        for(auto c : s)
            cnts[c - 'a']++;
        
        if(*min_element(cnts.begin(), cnts.end()) < k)    return -1;

        int left = 0, right = 0;
        int n = s.size();
        int ans = INT_MAX;
        while(right < n){
            cnts[s[right] - 'a']--;
            while(*min_element(cnts.begin(), cnts.end()) < k){
                cnts[s[left] - 'a']++;
                left++;
            }
            ans = min(ans, n - (right - left + 1));
            right++;
        }
        return ans;
    }
};