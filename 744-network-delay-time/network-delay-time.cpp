class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,1e8);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto i:times)
        {
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
        }
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty())
        {
            pair<int,int> temp=pq.top();
            pq.pop();

            int node=temp.second;
            int currdist=temp.first;

            for(auto it:adj[node])
            {
                if(dist[it.first]>(currdist+it.second))
                {
                    dist[it.first]=min(dist[it.first],currdist+it.second);
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e8) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};