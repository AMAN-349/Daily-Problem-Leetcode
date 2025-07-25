class Solution {
public:

    void dfs(int node, int par, vector<int>& nums, vector<vector<int>>& adj,
             vector<int>& in, vector<int>& out, vector<int>& xorsum, int& timer) {
        in[node] = ++timer;
        xorsum[node] = nums[node];
        for (auto i : adj[node]) {
            if (i != par) {
                dfs(i, node, nums, adj, in, out, xorsum, timer);
                xorsum[node] ^= xorsum[i];
            }
        }
        out[node] = ++timer;
    }

    bool isAncestor(int i, int j, vector<int>& in, vector<int>& out) {
        return (in[i] <= in[j] && out[i] >= out[j]);
    }

    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int> in(n, 0), out(n, 0), xorsum(n, 0);
        int timer = 0;
        dfs(0, -1, nums, adj, in, out, xorsum, timer);

        int ans = INT_MAX;

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int a = xorsum[i], b = xorsum[j], c;
                if (isAncestor(i, j, in, out)) {
                    int val1 = a ^ b;
                    int val2 = b;
                    int val3 = xorsum[0] ^ val1 ^ val2;
                    int maxi = max({val1, val2, val3});
                    int mini = min({val1, val2, val3});
                    ans = min(ans, maxi - mini);
                } else if (isAncestor(j, i, in, out)) {
                    int val1 = b ^ a;
                    int val2 = a;
                    int val3 = xorsum[0] ^ val1 ^ val2;
                    int maxi = max({val1, val2, val3});
                    int mini = min({val1, val2, val3});
                    ans = min(ans, maxi - mini);
                } else {
                    int val1 = a;
                    int val2 = b;
                    int val3 = xorsum[0] ^ val1 ^ val2;
                    int maxi = max({val1, val2, val3});
                    int mini = min({val1, val2, val3});
                    ans = min(ans, maxi - mini);
                }
            }
        }

        return ans;
    }
};
