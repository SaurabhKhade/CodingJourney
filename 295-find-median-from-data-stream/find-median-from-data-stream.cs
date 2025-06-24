public class MedianFinder {
    private readonly PriorityQueue<int, int> minHeap, maxHeap;
    public MedianFinder() {
        minHeap = new PriorityQueue<int, int>();
        maxHeap = new PriorityQueue<int, int>();
    }
    
    public void AddNum(int num) {
        if (maxHeap.Count == 0 || num < maxHeap.Peek()) {
            maxHeap.Enqueue(num, -num);
        } else {
            minHeap.Enqueue(num, num);
        }

        if (maxHeap.Count > minHeap.Count + 1) {
            var value = maxHeap.Dequeue();
            minHeap.Enqueue(value, value);
        } else if (maxHeap.Count + 1 < minHeap.Count) {
            var value = minHeap.Dequeue();
            maxHeap.Enqueue(value, -value);
        }
    }
    
    public double FindMedian() {
        if (maxHeap.Count == minHeap.Count) {
            return (Convert.ToDouble(maxHeap.Peek() + minHeap.Peek()))/2;
        }
        if (maxHeap.Count > minHeap.Count) {
            return maxHeap.Peek();
        }
        return minHeap.Peek();
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.AddNum(num);
 * double param_2 = obj.FindMedian();
 */