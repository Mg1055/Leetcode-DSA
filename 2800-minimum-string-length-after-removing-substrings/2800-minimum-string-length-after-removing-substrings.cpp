class Solution {
public:
    int minLength(string s) {
        // stack<int>st;

        // for(int i = 0; i < s.size(); i++){
        //     if(st.empty() == true){
        //         st.push(s[i]);
        //         continue;
        //     }

        //     if(s[i] == 'B' && st.top() == 'A')
        //         st.pop();
        //     else if(s[i] == 'D' && st.top() == 'C')
        //         st.pop();
        //     else
        //         st.push(s[i]);
        // }

        // return st.size();

        int stack_top = 0;
        for(auto c : s){
            if(stack_top > 0 && ((s[stack_top - 1] == 'A' && c == 'B') || (s[stack_top - 1] == 'C' && c == 'D')))
                stack_top--;
            else
                s[stack_top++] = c;
        }
        return stack_top;
    }
};