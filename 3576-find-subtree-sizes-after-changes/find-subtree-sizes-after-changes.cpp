class Solution {
public:

    vector<int> newParent;
    vector<int> last = vector<int>(26, -1);
 
    void dfs(int node,string& s,vector<vector<int>>& adj,vector<int>& parent)
    {
        int c=s[node]-'a';
        int old=last[c];

        if(old!=-1)
        {
            newParent[node]=old;
        }
        else{
            newParent[node]=parent[node];
        }

        last[c]=node;
        for(auto it:adj[node])
        {
            dfs(it,s,adj,parent);
        }
        last[c]=old;
    }

    void dfs2(int node,vector<vector<int>>& adj2,vector<int>& ans)
    {
        int sz=1;

        for(auto it:adj2[node])
        {
            dfs2(it,adj2,ans);
            sz+=ans[it];
        }

        ans[node]=sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n=parent.size();
        newParent.resize(n,0);

        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back(i);
        }

        dfs(0,s,adj,parent);

        vector<vector<int>> adj2(n);
        for(int i=1;i<n;i++)
        {
            adj2[newParent[i]].push_back(i);
        }

        vector<int> ans(n,0);

        dfs2(0,adj2,ans);

        return ans;
    }
};