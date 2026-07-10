class Solution {
public:
    int maxbit;

    int find(int u, int v, vector<int>& pos, vector<int>& far,
            vector<vector<int>>& table)
    {
        int l = pos[u];
        int r = pos[v];

        if (l > r)
            swap(l, r);

        int cnt = 0;

        for (int i = maxbit - 1; i >= 0; i--)
        {
            if (table[i][l] < r)
            {
                l = table[i][l];
                cnt += (1 << i);
            }
        }

        if (l < r)
        {
            if (far[l] == l)
                return -1;
            cnt++;
        }

        return cnt;
    }

    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int,int>> v;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(), v.end());

        vector<int> far(n);

        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && v[j].first - v[i].first <= maxDiff)
                j++;

            far[i] = j - 1;
        }

        maxbit = 0;
        while ((1 << maxbit) <= n)
            maxbit++;

        //binary lifting
        vector<vector<int>> table(maxbit,vector<int>(n,0));

        for(int i=0;i<n;i++)
        {
            table[0][i]=far[i];
        }

        for(int i=1;i<maxbit;i++)
        {
            for(int j=0;j<n;j++)
            {
                table[i][j]=table[i-1][table[i-1][j]];
            }
        }

        vector<int> pos(n);

        for (int i = 0; i < n; i++)
            pos[v[i].second] = i;

        for(auto i:queries)
        {
            int u=i[0];
            int v=i[1];

            ans.push_back(find(u,v,pos,far,table));
        }

        return ans;
    }
};