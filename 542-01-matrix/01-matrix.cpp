class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e8));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        while(!q.empty())
        {
            pair<int,int> p=q.front();
            q.pop();
            int currdist=dist[p.first][p.second];

            for(int i=0;i<4;i++)
            {
                int newrow=p.first+dx[i];
                int newcol=p.second+dy[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m)
                {
                    if(currdist+1<dist[newrow][newcol] && mat[newrow][newcol]!=0)
                    {
                        dist[newrow][newcol]=1+currdist;
                        q.push({newrow,newcol});
                    }
                }
            }
        }
        return dist;
    }
};