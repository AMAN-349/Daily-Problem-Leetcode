class Solution {
public:
    vector<int> exclusiveTime(int mn, vector<string>& logs) {
        int time=0;
        int n=logs.size();
        map<int,int> m;
        vector<int> ans;
        stack<pair<int,int>> s;
        for(int i=0;i<n;i++)
        {
            int p1 = logs[i].find(':');
            int p2 = logs[i].find(':', p1 + 1);

            int id = stoi(logs[i].substr(0, p1));
            string type = logs[i].substr(p1+1, p2 - p1 - 1);
            int t = stoi(logs[i].substr(p2+1));

            if(type=="start")
            {
                if(s.empty())
                {
                    s.push({id,t});
                    time=t;
                }
                else{
                    pair<int,int> prev=s.top();
                    m[prev.first]+=t-time;
                    time=t;
                    s.push({id,t});
                }
            }
            else{
                vector<pair<int,int>> v;
                while(!s.empty() && s.top().first!=id)
                {
                    v.push_back(s.top());
                    s.pop();
                }
                s.pop();
                for(auto i:v)
                {
                    s.push(i);
                }
                m[id]+=t-time+1;
                time=t+1;
            }
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};