class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        if(n==1)
        {
            if(values[0]%k==0)
            {
                return 1;
            }
        }
        vector<vector<int>> adjlist(n);
        vector<int> degree(n, 0);
        for(auto i:edges)
        {
            int val1=i[0];
            int val2=i[1];
            adjlist[val1].push_back(val2);
            adjlist[val2].push_back(val1);
            degree[val1]++;
            degree[val2]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        int ans=0;
        int sum=0;
        while(!q.empty())
        {
            int p=q.front();
            q.pop();
            if(values[p]%k==0)
            {
                ans++;
            }
            for(auto i:adjlist[p])
            {
                if(degree[i]>0)
                {
                    degree[i]--;
                    values[i]+=values[p]%k;
                    if(degree[i]==1)
                    {
                        q.push(i);
                    }
                }
            }
            degree[p]=0;
        }
        return ans;

    }
};