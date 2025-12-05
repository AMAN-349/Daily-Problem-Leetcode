class MyCalendarTwo {
public:
    map<int,int> m;
    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {
        m[startTime]+=1;
        m[endTime]-=1;
        int sum=0;
        for(auto i:m)
        {
            int curr=i.second;
            sum=sum+curr;
            if(sum>=3)
            {
                m[startTime]--;
                if(m[startTime]==0)
                {
                    m.erase(startTime);
                }
                m[endTime]++;
                if(m[endTime]==0)
                {
                    m.erase(endTime);
                }
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */