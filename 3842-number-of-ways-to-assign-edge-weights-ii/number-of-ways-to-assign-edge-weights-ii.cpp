class Solution {
public:
    vector<int> par;
    vector<int> level;
    vector<vector<int>> table;
    vector<vector<int>> adj;
    long long mod=1e9+7;
    int maxbit = 18;

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

    void dfs(int u, int p)
    {
        par[u] = p;
        for (auto v : adj[u])
        {
            if (v == p)
                continue;

            level[v] = level[u] + 1;
            dfs(v, u);
        }
    }

    void build(int n)
    {
        table.assign(maxbit, vector<int>(n + 1, 0));

        // 2^0-th ancestor
        table[0] = par;

        // Binary lifting table
        for (int p = 1; p < maxbit; p++)
        {
            for (int i = 1; i <= n; i++)
            {
                int temp = table[p - 1][i];
                if (temp != 0)
                    table[p][i] = table[p - 1][temp];
            }
        }
    }

    // Returns LCA node
    int getLCA(int u, int v)
    {
        if (level[u] < level[v])
            swap(u, v);

        int diff = level[u] - level[v];

        // Lift u to same level as v
        for (int i = maxbit - 1; i >= 0; i--)
        {
            if (diff & (1 << i))
                u = table[i][u];
        }

        if (u == v)
            return u;

        // Lift both together
        for (int i = maxbit - 1; i >= 0; i--)
        {
            if (table[i][u] != table[i][v])
            {
                u = table[i][u];
                v = table[i][v];
            }
        }

        return par[u];
    }

    // Returns distance between u and v
    int lca(int u, int v)
    {
        int w = getLCA(u, v);
        return level[u] + level[v] - 2 * level[w];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        par.assign(n + 1, 0);
        level.assign(n + 1, 0);
        adj.assign(n + 1, {});

        // Build tree
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Assume root is 1
        dfs(1, 0);
        build(n);

        vector<int> ans;
        for (auto &q : queries)
        {
            long long d = lca(q[0], q[1]);
            //d--;
            if(q[0]==q[1])
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(modPow(2, max(0LL, d - 1), mod));
            }
        }

        return ans;
    }
};