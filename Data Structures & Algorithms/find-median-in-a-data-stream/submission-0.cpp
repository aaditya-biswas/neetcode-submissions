
// Median from Data Stream 

class MedianFinder {
public:
    int size = 0;
    priority_queue<int> max_heap; // from 0 ... n /2 lb 
    priority_queue<int,vector<int>, greater<int>> min_heap; // from n / 2 (lb + 1) ... n
    MedianFinder() {
        ;
    }
    
    void addNum(int num) {
        size++;
        if (size % 2 == 1) {
            if (!min_heap.empty() && min_heap.top() <= num) {
                int min_top = min_heap.top();
                min_heap.pop();
                min_heap.push(num);
                max_heap.push(min_top);
            }
            else max_heap.push(num);
        }
        else {
            if (!max_heap.empty() && max_heap.top() >= num) {
                int max_top = max_heap.top();
                max_heap.pop();
                max_heap.push(num);
                min_heap.push(max_top);
            }
            else {
                min_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if (size % 2) return (double) max_heap.top();
        return (double) (max_heap.top() + min_heap.top()) / 2.0; 
    }
};
