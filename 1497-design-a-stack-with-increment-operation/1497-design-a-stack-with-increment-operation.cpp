class CustomStack {
public:
    vector<int> st, vec;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        if(st.size() == n)  return;
        st.push_back(x);
        vec.push_back(0);
    }
    
    int pop() {
        if(st.size() == 0)  return -1;
        int k = st.size() - 1;
        if(k > 0)   
            vec[k-1] += vec[k];
        int ret = st[k] + vec[k];
        st.pop_back();
        vec.pop_back();
        return ret;   
    }
    
    void increment(int l, int val) {
        int i = min(l, (int)st.size()) - 1;
        if(i >= 0)  vec[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */