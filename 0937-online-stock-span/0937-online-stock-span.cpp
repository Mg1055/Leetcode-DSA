class StockSpanner {
public:
    stack<pair<int,int>>st;
    int day;

    StockSpanner() {
        day = -1;
    }
    
    int next(int price) {
        day++;
        while(!st.empty() && st.top().first <= price) 
            st.pop();
        int pge = st.empty() ? -1 : st.top().second;
        int ans = day - pge;
        st.push({price,day});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */