class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        int n = ast.size();
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(ast[i] > 0 || st.empty()) {
                st.push(ast[i]);
            }
            else {
                while(!st.empty() && st.top() > 0 && st.top() < abs(ast[i])) 
                    st.pop();

                if(!st.empty() and st.top() == abs(ast[i]))
                    st.pop();
                else if(st.empty() || st.top() < 0)
                    st.push(ast[i]);
            }
        }

        n = st.size();
        vector<int> ans(n);
        for(int i = n-1; i >= 0; i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};