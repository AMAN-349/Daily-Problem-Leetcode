class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,2*w});
        }
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty())
        {
            int currdist=pq.top().first;
            int currnode=pq.top().second;
            pq.pop();

            for(auto it:adj[currnode])
            {
                if(dist[it.first]>currdist+it.second)
                {
                    dist[it.first]=currdist+it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist[n-1]==INT_MAX?-1:dist[n-1];
    }
};