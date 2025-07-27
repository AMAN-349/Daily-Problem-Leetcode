class MyCircularQueue {
public:
   
    vector<int> q;
    int front,back,n;
    int cap=0;

    MyCircularQueue(int k) {
        q.resize(k);
        n=k;
        front=-1;
        back=-1;
    }
    
    bool enQueue(int value) {
        if(cap==n) return false;
        if(front==-1)
        {
            front=(front+1)%n;
        }
        back=(back+1)%n;
        q[back]=value;
        cap++;
        return true;
    }
    
    bool deQueue() {
        if(cap==0)
        {
            return false;
        }
        cap--;
        if (cap == 0) {
            front = -1;
            back = -1;
        } else {
            front = (front + 1) % n;
        }
        return true;
    }
    
    int Front() {
        if (cap == 0) return -1;
        return q[front];
    }
    
    int Rear() {
        if (cap == 0) return -1;
        return q[back];
    }
    
    bool isEmpty() {
        if(cap==0) return true;
        return false;
    }
    
    bool isFull() {
        if(cap==n) return true;
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */