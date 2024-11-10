class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string prev = countAndSay(n-1);
        char c = prev[0];
        int cnt = 1;

        string res = "";
        for (int i = 1; i <= prev.size(); i++) {
            if (prev[i] == c) {
                cnt++;
            } 
            else {
                res += to_string(cnt);
                res.push_back(c);
                c = prev[i];
                cnt = 1;
            }
        }

        return res;
    }
};