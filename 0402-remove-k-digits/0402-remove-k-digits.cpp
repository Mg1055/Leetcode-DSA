class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char &c : num){
            while(ans.size() && ans.back() > c && k > 0){
                ans.pop_back();
                k--;
            }
            if(ans.size() || c != '0')
                ans.push_back(c);
        }

        while(ans.size() && k--)
            ans.pop_back();
        
        return ans.empty() ? "0" : ans;
    }
};