class MinStack {
public:
    stack<long long> st;
    long long currmini;
    MinStack() {
        currmini=-1;
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(1LL*val);
            currmini=1LL*val;
        }
        else if(val<currmini)
        {
            st.push((2LL*val)-currmini);
            currmini=1LL*val;
        }
        else{
            st.push(1LL*val);
        }
    }
    
    void pop() {
        if(st.top()<currmini)
        {
            currmini=(2LL*currmini-st.top());
            st.pop();
        }
        else{
            st.pop();
        }
    }
    
    int top() {
        long long t = st.top();
        if(t < currmini)
            return currmini;
        else
            return t;
    }
    
    int getMin() {
        return currmini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */