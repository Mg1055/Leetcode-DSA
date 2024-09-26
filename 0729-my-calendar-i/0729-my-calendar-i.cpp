class MyCalendar {
public:
    map<int,int>calendar;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(calendar.size() == 0){
            calendar[start] = end;
            return true;
        }
        auto curr = calendar.upper_bound(start);
        if(curr != calendar.end() && curr->first < end) return false;
        if(curr != calendar.begin() && (--curr)->second > start)    return false;
        calendar[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */