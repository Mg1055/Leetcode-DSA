class MedianFinder {
public:
    priority_queue<int>leftmaxh;
    priority_queue<int, vector<int>, greater<int>>rightminh;

    MedianFinder() {
    }
    
    void addNum(int num) {
        leftmaxh.push(num);
        rightminh.push(leftmaxh.top());
        leftmaxh.pop();
        if(rightminh.size() > leftmaxh.size()){
            leftmaxh.push(rightminh.top());
            rightminh.pop();
        }
    }
    
    double findMedian() {
        if(leftmaxh.size() > rightminh.size()) return leftmaxh.top();
        return (leftmaxh.top() + rightminh.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */