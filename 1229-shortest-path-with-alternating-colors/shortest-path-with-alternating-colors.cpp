class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> reds(n);
        vector<vector<int>> blues(n);

        for(auto it:redEdges)
        {
            int u=it[0];
            int v=it[1];
            reds[u].push_back(v);
        }

        for(auto it:blueEdges)
        {
            int u=it[0];
            int v=it[1];
            blues[u].push_back(v);
        }

        vector<vector<int>> dist(n, vector<int>(2, 1e8));
        dist[0][0]=0;
        dist[0][1]=0;

        vector<vector<int>> vis(n,vector<int>(2,false));

        queue<pair<int,int>> q;
        
        q.push({0, 0}); 
        q.push({0, 1});
        vis[0][0] = vis[0][1] = true;

        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int node=p.first;
            int color=p.second;

            if(color==0)
            {
                for(auto i:blues[node])
                {
                    if(!vis[i][1]){
                        vis[i][1]=true;
                        dist[i][1]=dist[node][0]+1;
                        q.push({i,1});
                    }
                }
            }
            else{
                for(auto i:reds[node])
                {
                    if(!vis[i][0]){
                        vis[i][0]=true;
                        dist[i][0]=dist[node][1]+1;
                        q.push({i,0});
                    }
                }
            }
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int best = min(dist[i][0], dist[i][1]);
            ans[i] = (best == 1e8 ? -1 : best);
        }

        return ans;

    }
};