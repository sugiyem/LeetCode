class MedianFinder {
    private PriorityQueue<Integer> smallHeap;
    private PriorityQueue<Integer> largeHeap;

    public MedianFinder() {
        smallHeap = new PriorityQueue<>(Collections.reverseOrder());
        largeHeap = new PriorityQueue<>();
    }
    
    public void addNum(int num) {
        if (smallHeap.isEmpty() || smallHeap.peek() > num) {
            smallHeap.add(num);
        } else {
            largeHeap.add(num);
        }
        
        if (smallHeap.size() - largeHeap.size() > 1) {
            largeHeap.add(smallHeap.poll());
        } else if (largeHeap.size() - smallHeap.size() > 1) {
            smallHeap.add(largeHeap.poll());
        }
    }
    
    public double findMedian() {
        if (smallHeap.size() == largeHeap.size()) {
            return (smallHeap.peek() + largeHeap.peek()) / 2.0;
        } else if (smallHeap.size() < largeHeap.size()) {
            return largeHeap.peek();
        } else {
            return smallHeap.peek();
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */