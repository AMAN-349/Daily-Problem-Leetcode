class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(k+1, false)));
        vis[0][0][k] = true;
        queue<tuple<int,int,int>> q;
        q.push({0,0,k});
        vis[0][0][k]=true;
        int steps=0;

        int dirx[4]={-1,0,1,0};
        int diry[4]={0,1,0,-1};

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto [i,j,rem_k]=q.front();
                q.pop();
                if(i==n-1 && j==m-1 && rem_k>=0) return steps;

                for(int x=0;x<4;x++)
                {
                    int newr=i+dirx[x];
                    int newc=j+diry[x];

                    if(newr<0 || newc<0 || newr>=n || newc>=m) continue;
                    int new_rem = rem_k - grid[newr][newc];

                    if(new_rem < 0) continue;

                    if(!vis[newr][newc][new_rem])
                    {
                        vis[newr][newc][new_rem]=true;
                        q.push({newr,newc,new_rem});
                    }
                }

            }
            steps++;
        }
        return -1;
    }
};