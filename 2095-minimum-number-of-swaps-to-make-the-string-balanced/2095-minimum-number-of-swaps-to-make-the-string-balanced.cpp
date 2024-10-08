class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        
        for(int i = 0; i < s.size(); i++){
            if(st.empty())
                st.push(s[i]);
            else if(st.top() == '[' && s[i] == ']')
                st.pop();
            else
                st.push(s[i]);
        }
        
        return (st.size()/2 + 1)/2;
    }
};