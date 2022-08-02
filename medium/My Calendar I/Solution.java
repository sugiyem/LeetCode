class MyCalendar {
    private TreeMap<Integer, Integer> calendar;
    
    public MyCalendar() {
        this.calendar = new TreeMap<>();
    }
    
    public boolean book(int start, int end) {
        Integer x = this.calendar.lowerKey(end);
        if (x == null || calendar.get(x) <= start) {
            this.calendar.put(start, end);
            return true;
        }
        return false;
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */