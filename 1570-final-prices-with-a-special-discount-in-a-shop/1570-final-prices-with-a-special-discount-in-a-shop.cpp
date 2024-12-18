class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n = prices.size();
        st.push(prices[n-1]);
        for(int i = n-2; i >= 0; i--){
            int initialPrice = prices[i];
            if(initialPrice >= st.top()){
                prices[i] -= st.top();
                st.push(initialPrice);
            }
            else{
                while(!st.empty() && initialPrice < st.top())
                    st.pop();
                if(!st.empty())
                    prices[i] -= st.top();
                st.push(initialPrice);
            }
        }
        return prices;
    }
};