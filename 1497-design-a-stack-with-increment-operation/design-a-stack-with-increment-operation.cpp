class CustomStack {
public:
    stack<int> s;
    int cap;
    CustomStack(int maxSize) {
        cap=maxSize;
    }
    
    void push(int x) {
        if(s.size()==cap)
        {
            return;
        }
        s.push(x);
    }
    
    int pop() {
        if(!s.empty())
        {
            int ans=s.top();
            s.pop();
            return ans;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        stack<int> temp;
        while(!s.empty())
        {
            temp.push(s.top());
            s.pop();
        }
        while(k-- && !temp.empty())
        {
            s.push(temp.top()+val);
            temp.pop();
        }
        while(!temp.empty())
        {
            s.push(temp.top());
            temp.pop();
        }

    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */