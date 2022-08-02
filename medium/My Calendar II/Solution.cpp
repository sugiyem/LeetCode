class MyCalendarTwo {
public:
    MyCalendarTwo() {
        return;
    }
    
    bool book(int start, int end) {
        ++calendar[start];
        --calendar[end];
        int check = 0;
        for (auto it = calendar.begin(); it != calendar.end(); ++it) {
            check += it -> second;
            if (check == 3) {
                --calendar[start];
                ++calendar[end];
                return false;
            }
        }
        return true;
    }
    
private:
    map<int, int> calendar;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */