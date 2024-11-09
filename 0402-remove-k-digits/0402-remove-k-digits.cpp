class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(int i = 0; i < num.length(); i++){
            while(k && !st.empty() && (num[i] - '0') < st.top()){
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }

        // if [12345] and k = 2, so no removal in the while loop. So remove now
        while(k-- > 0)
            st.pop();

        string ans = "";
        while(!st.empty()){
            ans.push_back((st.top() + '0'));
            st.pop();
        }

        // trim leading zeroes
        while(ans.size() != 0 && ans.back() == '0')
            ans.pop_back();

        reverse(ans.begin(),ans.end());
        return ans.empty() ? "0" : ans;
    }
};