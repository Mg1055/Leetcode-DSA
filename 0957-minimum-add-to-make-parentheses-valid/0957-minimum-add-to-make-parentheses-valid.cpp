class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n = s.size();

        for(char c : s){
            if(st.empty())
                st.push(c);
            else if(st.top() == '(' && c == ')')
                st.pop();
            else 
                st.push(c);
        }

        
        int ans = st.size();
        while(!st.empty()){
            cout << st.top() << endl;
            st.pop();
        }
        return ans;
    }
};