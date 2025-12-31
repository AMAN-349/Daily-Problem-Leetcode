class Solution {
public:

    void find(int i,int j,vector<vector<int>>& v,vector<vector<int>>& vis)
    {
        vis[i][j]=1;
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        int n=v.size(), m=v[0].size();

        for(int k=0;k<4;k++)
        {
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
            vis[nrow][ncol]==0 && v[nrow][ncol]==0)
            {
                find(nrow,ncol,v,vis);
            }
        }
    }


    void dfs(vector<vector<int>>& v,vector<vector<int>>& vis,int m)
    {
        for(int i=0;i<m;i++)
        {
            if(v[0][i]==0){
                find(0,i,v,vis);
            }
        }
    }

    int tofind(int start,int end,vector<vector<int>>& v,vector<vector<int>>& vis,vector<vector<int>>& cells)
    {
        int n=v.size();
        int m=v[0].size();
        vis.assign(n, vector<int>(m,0));
        v.assign(n, vector<int>(m, 0));
        for(int i=start;i<=end;i++)
        {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            v[r][c] = 1;
        }
        dfs(v, vis, m);
        int j=0;
        for(j=0;j<m;j++)
        {
            if(vis[n-1][j]==1)
            {
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int ans=0;
        int n=row,m=col;
        vector<vector<int>> v(n,vector<int>(m,0));
        vector<vector<int>> vis(n,vector<int>(m,0));
        int lb=0;
        int ub=cells.size()-1;
        while(lb<=ub)
        {
            int mid=(lb+ub)/2;
            if(tofind(0,mid,v,vis,cells))
            {
                ans=mid+1;
                lb=mid+1;
            }
            else{
                ub=mid-1;
            }
        }
        return ans;
    }
};