class TaskManager {
public:
    unordered_map<int,pair<int,int>> m1;
    map<int,set<int>> m2;

    TaskManager(vector<vector<int>>& tasks) {
        for(auto i:tasks)
        {
            m1[i[1]]={i[0],i[2]};
            m2[i[2]].insert(i[1]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        m1[taskId]={userId, priority};
        m2[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        int oldp = m1[taskId].second;
        m1[taskId].second=newPriority;
        m2[oldp].erase(taskId);
        if(m2[oldp].size()==0)
        {
            m2.erase(oldp);
        }
        m2[newPriority].insert(taskId);
    }
    
    void rmv(int taskId) {
        int oldp = m1[taskId].second;
        m1.erase(taskId);
        m2[oldp].erase(taskId);
        if(m2[oldp].size()==0)
        {
            m2.erase(oldp);
        }
    }
    
    int execTop() {
        if(m2.size()==0)
        {
            return -1;
        }
        auto it = m2.end();
        --it;
        int priority = (*it).first;
        set<int>& s = it->second;
        int ans;
        if (!s.empty()) {
            auto it2 = s.end();
            --it2;
            ans = *it2;
        }
        int res = m1[ans].first;
        rmv(ans);
        return res;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */