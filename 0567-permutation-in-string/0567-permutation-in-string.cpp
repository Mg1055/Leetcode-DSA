class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(n > m)   return false;
        vector<int>chars1(26,0),chars2(26,0);
        int i;
        for(i = 0; i < n; i++){
            chars2[s2[i]-'a']++;
            chars1[s1[i]-'a']++;
        }
        for(;i < m; i++){
            if(chars1 == chars2)    
                return true;
            chars2[s2[i]-'a']++;
            chars2[s2[i-n]-'a']--;
        }
        if(chars1 == chars2)    
            return true;
        return false;
    }
};