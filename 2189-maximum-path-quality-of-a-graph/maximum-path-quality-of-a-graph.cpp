class Solution {
public:
    
    int ans=INT_MIN;

    void find(int vertex,int time,vector<vector<pair<int,int>>>& adj,vector<int>& values,int currvalue,vector<int>& vis)
    {
        if (time < 0) return;
        if(vertex==0)
        {
            ans=max(ans,currvalue);
        }
        for(auto it:adj[vertex])
        {
            int u=it.first;
            int w=it.second;
            if(time>=w)
            {
                bool firstVisit = (vis[u] == 0);
                vis[u]++;

                find(u,time-w,adj,values,currvalue+(firstVisit?values[u]:0),vis);

                vis[u]--;
            }
        }
    }

    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>> adj(n);

        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            int w=i[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> vis(n,false);
        vis[0]=true;
        find(0,maxTime,adj,values,values[0],vis);
        return ans;
    }
};