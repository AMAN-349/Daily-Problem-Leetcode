class Solution {
public:
    int n;
    int m;
    bool isposs(int k, vector<vector<int>>& arr)
    {
        int minr = n;
        int maxr = -1;
        int minc = m;
        int maxc = -1;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                int curr = arr[i][j];

                if(i-k >= 0)
                    curr -= arr[i-k][j];

                if(j-k >= 0)
                    curr -= arr[i][j-k];

                if(i-k >= 0 && j-k >= 0)
                    curr += arr[i-k][j-k];

                if(curr == k*k)
                {
                    minr = min(minr, i-k);
                    minc = min(minc, j-k);
                    maxr = max(maxr, i-k);
                    maxc = max(maxc, j-k);
                }
            }
        }

        return maxr - minr >= k || maxc - minc >= k;
    }

    int maxArea(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();

        vector<vector<int>> prefix=mat;
        vector<vector<int>> suffix=mat;

        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                prefix[i][j]+=prefix[i][j-1];
            }
        }

        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                prefix[j][i]+=prefix[j-1][i];
            }
        }

        int ans=0;
        int l=1;
        int r=min(n,m);

        while(l<=r)
        {
            int m=(l+r)/2;

            if(isposs(m,prefix))
            {
                ans=max(ans,m*m);
                l=m+1;
            }
            else{
                r=m-1;
            }
        }

        return ans;
    }
};