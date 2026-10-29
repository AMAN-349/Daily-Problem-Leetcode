class Solution {
public:
    vector<int> sz, heavy, par, depth, head, pos, base, ftree;
    int idx = 1;

    // Fenwick tree: XOR update
    void add(int i, int val, int n) {
        while (i <= n) {
            ftree[i] ^= val;
            i += i & (-i);
        }
    }

    // Prefix XOR
    int query(int i) {
        int ans = 0;
        while (i > 0) {
            ans ^= ftree[i];
            i -= i & (-i);
        }
        return ans;
    }

    // XOR of range [l, r]
    int rangeQuery(int l, int r) {
        return query(r) ^ query(l - 1);
    }

    void dfs(int node, int p, vector<vector<int>>& adj) {
        par[node] = p;
        sz[node] = 1;
        heavy[node] = -1;

        int maxSize = 0;

        for (int c : adj[node]) {
            if (c == p) continue;

            depth[c] = depth[node] + 1;
            dfs(c, node, adj);

            sz[node] += sz[c];

            if (sz[c] > maxSize) {
                maxSize = sz[c];
                heavy[node] = c;
            }
        }
    }

    void dfshld(int node, int chain, string& s,
                vector<vector<int>>& adj) {
        head[node] = chain;
        pos[node] = idx;

        // Represent the character as a bit mask
        base[idx] = (1 << (s[node] - 'a'));
        idx++;

        if (heavy[node] != -1) {
            dfshld(heavy[node], chain, s, adj);
        }

        for (int c : adj[node]) {
            if (c == par[node] || c == heavy[node])
                continue;

            dfshld(c, c, s, adj);
        }
    }

    // XOR mask of the path from a to b
    int pathQuery(int a, int b, int n) {
        int mask = 0;

        while (head[a] != head[b]) {
            if (depth[head[a]] < depth[head[b]]) {
                swap(a, b);
            }

            mask ^= rangeQuery(pos[head[a]], pos[a]);
            a = par[head[a]];
        }

        if (depth[a] > depth[b]) {
            swap(a, b);
        }

        mask ^= rangeQuery(pos[a], pos[b]);

        return mask;
    }

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        sz.assign(n, 0);
        heavy.assign(n, -1);
        par.assign(n, -1);
        depth.assign(n, 0);
        head.assign(n, 0);
        pos.assign(n, 0);
        base.assign(n + 1, 0);
        ftree.assign(n + 1, 0);
        idx = 1;

        dfs(0, -1, adj);
        dfshld(0, 0, s, adj);

        // Build Fenwick tree
        for (int i = 1; i <= n; i++) {
            add(i, base[i], n);
        }

        vector<bool> ans;

        for (auto& q : queries) {
            stringstream ss(q);
            string op, x, y;

            ss >> op >> x >> y;

            int u = stoi(x);

            if (op == "query") {
                int v = stoi(y);

                int mask = pathQuery(u, v, n);

                // At most one character can have an odd frequency
                ans.push_back(__builtin_popcount(
                    static_cast<unsigned int>(mask)
                ) <= 1);
            } else {

                char ch = y[0];

                int oldMask = 1 << (s[u] - 'a');
                int newMask = 1 << (ch - 'a');

                add(pos[u], oldMask ^ newMask, n);
                s[u] = ch;
            }
        }

        return ans;
    }
};