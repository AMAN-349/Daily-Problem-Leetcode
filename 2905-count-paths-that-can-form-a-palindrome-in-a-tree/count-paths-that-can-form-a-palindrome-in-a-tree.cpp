class Solution {
public:

    int n;
    void findPath(vector<int>& v,vector<vector<pair<int,char>>>& adj,int path,int i,
              int par)
    {
        v[i] = path;

        for (auto &it : adj[i])
        {
            int next = it.first;
            char ch = it.second;

            if (next != par)
            {
                int newPath = path ^ (1 << (ch - 'a'));
                findPath(v, adj, newPath, next, i);
            }
        }
    }

    bool ispow2(int temp)
    {
        return temp > 0 && (temp & (temp - 1)) == 0;
    }

    long long countPalindromePaths(vector<int>& parent, string s) {
        n=s.size();
        vector<vector<pair<int,char>>> adj(n);

        for(int i=1;i<n;i++)
        {
            int par=parent[i];
            adj[par].push_back({i,s[i]});
            adj[i].push_back({par,s[i]});
        }


        vector<int> v(n);
        findPath(v,adj,0,0,-1);
        long long ans = 0;

        unordered_map<int, long long> freq;

        for (int i = 0; i < n; i++)
        {
            ans += freq[v[i]];

            for (int k = 0; k < 26; k++)
                ans += freq[v[i] ^ (1 << k)];

            freq[v[i]]++;
        }
        return ans;

    }
};