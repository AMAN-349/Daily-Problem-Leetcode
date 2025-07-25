class FreqStack {
public:

    stack<int> st;
    map<int,int> m;
    map<int,stack<int>> group;
    int ans=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        m[val]++;
        ans = max(ans, m[val]);
        group[m[val]].push(val);
    }
    
    int pop() {
        int val=group[ans].top();
        group[ans].pop();
        m[val]--;
        if(group[ans].empty())
        {
            ans--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */