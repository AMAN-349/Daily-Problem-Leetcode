class Solution {
public:

    static bool cmp(vector<int>& v1,vector<int>& v2)
    {
        return v1[2]<v2[2];
    }

    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        set<int> known;
        known.insert(0);
        known.insert(firstPerson);
        sort(meetings.begin(),meetings.end(),cmp);
        vector<vector<pair<int,int>>> v;
        set<int> vis;
        for(auto i:meetings)
        {
            if(vis.find(i[2])==vis.end())
            {
                vis.insert(i[2]);
                v.push_back({});
            }
            v.back().push_back({i[0],i[1]});
        }
        for(auto i:v)
        {
            set<int> curr;
            unordered_map<int,vector<int>> graph;
            for(auto j:i)
            {
                int a1=j.first;
                int a2=j.second;
                graph[a1].push_back(a2);
                graph[a2].push_back(a1);
                if(known.find(a1)!=known.end())
                {
                    curr.insert(a1);
                }
                if(known.find(a2)!=known.end())
                {
                    curr.insert(a2);
                }
            }
            queue<int> q;
            for(int i:curr)
            {
                q.push(i);
            }
            while(!q.empty())
            {
                int temp=q.front();
                q.pop();
                known.insert(temp);
                for (int neigh : graph[temp]) {
                    if (known.find(neigh) == known.end()) {
                        known.insert(neigh);
                        q.push(neigh);
                    }
                }
            }
        }
        vector<int> ans(known.begin(),known.end());
        return ans;
    }
};