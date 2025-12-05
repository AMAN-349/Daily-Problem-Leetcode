class MyCalendarThree {
public:
    map<int,int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]+=1;
        mp[endTime]-=1;
        map<int,int> m=mp;
        int sum=0;
        int ans=0;
        for(auto &i:m)
        {
            sum=sum+i.second;
            i.second=sum;
            ans=max(ans,i.second);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */