class Solution {
public:

    int triplet(vector<int>& v)
    {
        sort(v.begin(),v.end());
        long long a=v[0];
        long long b=v[1];
        long long c=v[2];
        long long ans=(1LL*a*a + b*b);
        long long ans2=(1LL*c*c);
        return ans==ans2;
        
    }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        map<int,vector<int>> m;
        int dist=0;
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<pair<int,int>> q;
        vector<int> vis(n,false);
        q.push({x,0});
        vis[x]=true;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            m[temp.first].push_back(temp.second);
            int dis=temp.second;
            for(auto it:adj[temp.first])
            {
                if(!vis[it]) 
                {
                    vis[it]=true;
                    q.push({it,dis+1});
                }
            }
        }
        vis.assign(n,false);
        q.push({y,0});
        vis[y]=true;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            m[temp.first].push_back(temp.second);
            int dis=temp.second;
            for(auto it:adj[temp.first])
            {
                if(!vis[it]) 
                {
                    vis[it]=true;
                    q.push({it,dis+1});
                }
            }
        }

        vis.assign(n,false);
        q.push({z,0});
        vis[z]=true;
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            m[temp.first].push_back(temp.second);
            int dis=temp.second;
            for(auto it:adj[temp.first])
            {
                if(!vis[it]) 
                {
                    vis[it]=true;
                    q.push({it,dis+1});
                }
            }
        }
        int ans=0;
        for(auto it:m)
        {
            vector<int> v=it.second;
            if(triplet(v))
            {
                ans++;
            }
        }
        return ans;


    }
};