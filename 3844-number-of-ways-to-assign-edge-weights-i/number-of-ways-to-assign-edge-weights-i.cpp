class Solution {
public:
    long long mod=1e9+7;
    long long modPow(long long a, long long b, long long mod)
    {
        long long res = 1;
        while (b)
        {
            if (b & 1) res = (res * a) % mod;
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(100002);
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> vis(100002,0);
        vis[1]=1;
        q.push(1);
        int sz=0;
        while(!q.empty())
        {
            int temp=q.size();
            for(int i=0;i<temp;i++)
            {
                int tp=q.front();
                q.pop();
                for(auto i:adj[tp])
                {
                    if(!vis[i])
                    {
                        vis[i]=1;
                        q.push(i);
                    }
                }
            }
            sz++;
        }
        sz--;
        if(sz==1) return 1;
        long long answer = modPow(2, sz - 1, mod);
        return answer;
    }
};