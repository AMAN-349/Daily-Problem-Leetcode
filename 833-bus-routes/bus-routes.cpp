class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source==target) return 0;
        unordered_map<int,vector<int>> sb;
        for(int i=0;i<routes.size();i++)
        {
            for(auto j:routes[i])
            {
                sb[j].push_back(i);
            }
        }

        unordered_set<int> visitedstops;
        unordered_set<int> visitedBus;
        queue<int> q;
        q.push(source);
        int buses=0;

        while(!q.empty())
        {
            int sz=q.size();
            buses++;
            while(sz--)
            {
                int temp=q.front();
                q.pop();
                for(auto bus:sb[temp])
                {
                    if (visitedBus.count(bus)) continue;
                    visitedBus.insert(bus);
                    for(auto allstops:routes[bus])
                    {
                        if(allstops==target) return buses;

                        if(visitedstops.find(allstops)==visitedstops.end())
                        {
                            visitedstops.insert(allstops);
                            q.push(allstops);
                        }
                    }
                }
            }
        }
        return -1;
    }
};