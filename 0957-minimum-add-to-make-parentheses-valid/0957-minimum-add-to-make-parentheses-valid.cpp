class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n = s.size();
        int open_cnt = 0;
        int close_cnt = 0;


        for(char c : s){
            if(c == '(')
                open_cnt++;
            else{
                open_cnt--;
                if(open_cnt < 0){
                    open_cnt = 0;
                    close_cnt++;  
                }
            }
        }
        return open_cnt + close_cnt;
    }
};