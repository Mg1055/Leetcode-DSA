class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char c : expression) {
            if (c == ',' || c == '(')
                continue;  
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                st.push(c);
            }
            else if (c == ')') {
                int true_cnt = 0, false_cnt = 0;

                while (st.top() != '!' && st.top() != '&' && st.top() != '|') {
                    char tf = st.top();
                    st.pop();
                    if (tf == 't') true_cnt++;
                    if (tf == 'f') false_cnt++;
                }
                char op = st.top();
                st.pop();
                char char_to_push = 'a';
                if (op == '!') {
                    char_to_push = (true_cnt > 0) ? 'f' : 't';
                } else if (op == '&') {
                    char_to_push = (false_cnt > 0) ? 'f' : 't';
                } else {
                    char_to_push = (true_cnt > 0)  ? 't' : 'f';
                }
                st.push(char_to_push);
            }
        }
        return st.top() == 't';
    }
};