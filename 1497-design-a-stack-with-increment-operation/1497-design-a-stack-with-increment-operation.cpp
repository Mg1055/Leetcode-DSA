class CustomStack {
public:
    vector<int>st;
    int i;
    CustomStack(int maxSize) {
        for(int j = 0; j < maxSize; j++)    st.push_back(0);
        i = 0;
    }
    
    void push(int x) {
        if(i >= st.size())  return;
        st[i] = x;
        i++;
    }
    
    int pop() {
        if(i == 0)  return -1;
        i--;
        int ret = st[i];
        st[i] = 0;
        return ret;
    }
    
    void increment(int k, int val) {
        k = (k > st.size()) ? st.size() : k;
        for(int j = 0; j < k ; j++){
            st[j] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */