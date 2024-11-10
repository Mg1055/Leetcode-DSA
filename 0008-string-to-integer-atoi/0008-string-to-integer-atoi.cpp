class Solution {
public:

    bool isDigit(char ch){
        return ch >= '0' && ch <= '9';
    } 

    int myAtoi(string s) {
        int n = s.size();

        if(n == 0)  return 0;

        int ind = 0;
        while(ind < n && s[ind] == ' ') // skipping white spaces
            ind++;

        bool isNegative = false;
        if(ind < n){
            if(s[ind] == '-'){
                isNegative = true;
                ind++;
            }
            else if(s[ind] == '+'){
                ind++;
            }
        }

        int res = 0;
        while(ind < n && isDigit(s[ind])){
            int digit = s[ind] - '0';
            if(res > (INT_MAX / 10) || (res == (INT_MAX / 10) && digit > 7))
                return isNegative ? INT_MIN : INT_MAX;

            res = (res*10) + digit;
            ind++;
        }

        return isNegative ? -res : res;
    }
};