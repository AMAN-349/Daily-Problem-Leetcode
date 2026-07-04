class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it:roads)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> dist(n+1,1e8);
        queue<int> q;
        q.push(1);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            int currdist=dist[temp];

            for(auto it:adj[temp])
            {
                int node=it.first;
                int newdist=it.second;
                newdist=min(currdist,newdist);
                if(newdist<dist[node])
                {
                    dist[node]=newdist;
                    q.push(node);
                }
            }
        }
        return dist[n];
    }
};