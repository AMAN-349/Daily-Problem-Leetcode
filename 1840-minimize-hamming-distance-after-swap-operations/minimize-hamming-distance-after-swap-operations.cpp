class Solution {
public:

    class Union{
        vector<int> rank;
        vector<int> par;

        public:

        Union(int n)
        {
            rank.resize(n,0);
            par.resize(n,0);
            for(int i=0;i<n;i++)
            {
                par[i]=i;
            }
        }

        int findPar(int i)
        {
            if(i==par[i])
            {
                return i;
            }
            return par[i]=findPar(par[i]);
        }

        void addUnion(int u,int v)
        {
            int p1=findPar(u);
            int p2=findPar(v);
            if(p1==p2)
            {
                return;
            }
            if(rank[p1]<rank[p2])
            {
                par[p1]=p2;
            }
            else if(rank[p1]>rank[p2])
            {
                par[p2]=p1;
            }
            else{
                par[p1]=p2;
                rank[p2]++;
            }
        }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        vector<int> v;
        int n=source.size();
        for(int i=0;i<source.size();i++)
        {
            if(source[i]!=target[i])
            {
                v.push_back(i);
            }
        }
        Union u(n);

        for(auto i:allowedSwaps)
        {
            u.addUnion(i[0],i[1]);
        }

        unordered_map<int, unordered_map<int,int>> mp;

        for (int i = 0; i < n; i++) {
            int p = u.findPar(i);
            mp[p][source[i]]++;
        }

        int ans=0;

        for (int i = 0; i < n; i++) {
            int p = u.findPar(i);

            if (mp[p][target[i]] > 0) {
                mp[p][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};