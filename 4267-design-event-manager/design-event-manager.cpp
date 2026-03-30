struct cmp {
    bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
        if(a.second == b.second) 
            return a.first > b.first; 
        return a.second < b.second; 
    }
};

class EventManager {
public:

    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    set<pair<int,int>> s;
    unordered_map<int,int> m;
    EventManager(vector<vector<int>>& events) {
        for(auto i:events)
        {
            pq.push({i[0],i[1]});
            m[i[0]]=i[1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        if(m.find(eventId)!=m.end())
        {
            s.insert({eventId,m[eventId]});

            if(s.find({eventId,newPriority})==s.end())
            {
                pq.push({eventId,newPriority});
            }
            else{
                s.erase({eventId,newPriority});
            }
            m[eventId]=newPriority;
        }
    }
    
    int pollHighest() {
        while(!pq.empty() && s.find(pq.top())!=s.end())
        {
            s.erase(pq.top());
            pq.pop();
        }
        if(pq.empty()) return -1;
        int ans=pq.top().first;
        pq.pop();
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */