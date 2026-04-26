class Solution {
public:
    int ans;
    int n;

    void dfs(int node,vector<int>& vis,vector<vector<int>>& filterededges)
    {
        vis[node]=1;
        for(auto i:filterededges[node])
        {
            if(!vis[i])
            {
                dfs(i,vis,filterededges);
            }
        }
    }

    bool isposs(unordered_set<int>& temp,vector<vector<int>>& edges,vector<int>& nums)
    {
        vector<vector<int>> filterededges(n);
        for(auto i:edges)
        {
            if(temp.find(i[0])!=temp.end() && temp.find(i[1])!=temp.end())
            {
                filterededges[i[0]].push_back(i[1]);
                filterededges[i[1]].push_back(i[0]);
            }
        }

        int cnt=0;
        vector<int> vis(n,0);

        for(auto i:temp)
        {
            if(!vis[i])
            {
                dfs(i,vis,filterededges);
                cnt++;
            }
        }
        return cnt==1;
    }

    void find(int i,vector<int>& nums,vector<vector<int>>& edges,unordered_set<int>& temp,int sum)
    {
        if(i==n)
        {
            if(isposs(temp,edges,nums) && sum%2==0)
            {
                ans++;
            }
            return;
        }
        find(i+1,nums,edges,temp,sum);
        temp.insert(i);
        find(i+1,nums,edges,temp,sum+nums[i]);
        temp.erase(i);
    }

    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        ans=0;
        n=nums.size();
        unordered_set<int> temp;
        find(0,nums,edges,temp,0);
        return ans;
    }
};