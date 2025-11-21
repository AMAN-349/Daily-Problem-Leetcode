class MyCircularQueue {
public:
    vector<int> v;
    int n;
    int front=-1;
    int rear=-1;
    MyCircularQueue(int k) {
        n=k;
        v.resize(k);
    }
    
    bool enQueue(int value) {
        if((rear+1)%n==front)
        {
            return false;
        }
        rear=(rear+1)%n;
        if(front==-1)
        {
            front=rear;
        }
        v[rear]=value;
        return true;
    }
    
    bool deQueue() {
        if(front==-1)
        {
            return false;
        }
        if(front==rear)
        {
            front=-1;
            rear=-1;
            return true;
        }
        front=(front+1)%n;
        return true;
    }
    
    int Front() {
        return front==-1?-1:v[front];
    }
    
    int Rear() {
        return rear==-1?-1:v[rear];
    }
    
    bool isEmpty() {
        return front==-1;
    }
    
    bool isFull() {
        return (rear + 1) % n == front;
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