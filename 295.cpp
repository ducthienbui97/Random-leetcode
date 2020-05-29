// Leetcode 295. Find Median from Data Stream
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int> >  right;
    MedianFinder() {
        
    }
    void balance(){
        while(!left.empty() && !right.empty() && left.top() > right.top()){
            int l = left.top(); left.pop();
            int r = right.top(); right.pop();
            swap(l,r);
            left.push(l);
            right.push(r);
        }
    }
    void addNum(int num) {
        left.push(num);
        balance();
        if(left.size() > right.size()){
            right.push(left.top());
            left.pop();
        }
    }
    
    double findMedian() {
        if(left.size()  == right.size())
            return 0.5*(left.top() + right.top());
        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
