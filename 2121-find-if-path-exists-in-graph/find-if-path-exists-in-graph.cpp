class Solution {
public:

    bool dfs(int source,vector<vector<int>>& adj,int dest,vector<int>& vis)
    {
        if(source==dest)
        {
            return true;
        }
        vis[source]=true;
        for(auto it:adj[source])
        {
            if(!vis[it])
            {
                if(dfs(it,adj,dest,vis)) return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n,false);

        return dfs(source,adj,destination,vis);
    }
};