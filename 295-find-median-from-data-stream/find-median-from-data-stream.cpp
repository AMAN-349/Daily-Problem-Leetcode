class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int>,greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        if(!minheap.empty() && maxheap.top() > minheap.top()) {
            int temp = maxheap.top(); maxheap.pop();
            minheap.push(temp);
        }

        if(maxheap.size()>minheap.size()+1)
        {
            int temp = maxheap.top(); maxheap.pop();
            minheap.push(temp);
        }

        if(minheap.size()>maxheap.size()+1)
        {
            int temp = minheap.top(); minheap.pop();
            maxheap.push(temp);
        }
    }
    
    double findMedian() {
        if(maxheap.size()==minheap.size()){
            double t1=maxheap.top();
            double t2=minheap.top();
            double ans=(double)(t1+t2)/2.0;
            return ans;
        }
        else if(maxheap.size()>minheap.size())
        {
            return maxheap.top();
        }
        return minheap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */