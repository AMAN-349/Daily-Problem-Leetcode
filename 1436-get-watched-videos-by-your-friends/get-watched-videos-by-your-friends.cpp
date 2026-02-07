class Solution {
public:

    vector<string> find(map<string,int>& ans)
    {
        vector<pair<string,int>> v(ans.begin(), ans.end());
        sort(v.begin(),v.end(),[](pair<string,int>& a,pair<string,int>& b)
        {
            if(a.second==b.second)
            {
                return a.first<b.first;
            }
            return a.second<b.second;
        });
        vector<string> res;
        for(auto i:v)
        {
            res.push_back(i.first);
        }
        return res;
    }

    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& adj, int id, int level) {
        int n=adj.size();
        queue<int> q;
        q.push(id);
        vector<int> vis(n+1,false);
        vis[id]=true;
        int clevel=0;
        vector<string> res;

        if(level==0)
        {
            return watchedVideos[id];
        }

        while(!q.empty())
        {
            int sz=q.size();
            map<string,int> ans;
            while(sz--)
            {
                int temp=q.front();
                q.pop();

                for(auto i:adj[temp])
                {
                    if(!vis[i])
                    {
                        q.push(i);
                        for(auto j:watchedVideos[i])
                        {
                            ans[j]++;
                        }
                        vis[i]=true;
                    }
                }
            }
            clevel++;
            if(clevel==level)
            {
                return find(ans);
            }
        }
        return res;
    }
};