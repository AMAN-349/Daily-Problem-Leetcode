class Solution {
public:

    bool isvalid(int x,int y,int n,int m)
    {
        return x>=0 && x<n && y>=0 && y<m;
    }

    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));


        queue<pair<int,pair<int,int>>> q;

        for(auto i:sources)
        {
            q.push({i[0],{i[1],i[2]}});
            ans[i[0]][i[1]]=i[2];
            vis[i[0]][i[1]]=1;
        }

        while(!q.empty())
        {
            int sz=q.size();
            map<pair<int,int>,int> mp;

            while(sz--)
            {
                pair<int,pair<int,int>> p=q.front();
                int x=p.first;
                int y=p.second.first;
                int cl=p.second.second;
                q.pop();

                int dx[4]={-1,0,1,0};
                int dy[4]={0,1,0,-1};

                for(int i=0;i<4;i++)
                {
                    int currx=x+dx[i];
                    int curry=y+dy[i];
                    if(isvalid(currx,curry,n,m) && !vis[currx][curry])
                    {
                        mp[{currx, curry}] = max(mp[{currx, curry}], cl);
                    }
                }
            }
            for(auto i:mp)
            {
                int x=i.first.first;
                int y=i.first.second;
                int cl=i.second;

                ans[x][y]=cl;
                q.push({x,{y,cl}});
                vis[x][y]=1;
            }

        }
        return ans;
    }
};