class Solution {
public:

    vector<int> find(int num)
    {
        vector<int> ans;
        for(int i = 2; i * i <= num; i++)
        {
            if(num % i == 0)
            {
                ans.push_back(i);

                while(num % i == 0)
                {
                    num /= i;
                }
            }
        }
        if(num > 1)
        {
            ans.push_back(num);
        }
        return ans;
    }

    int minJumps(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> m;

        for(int i = 0; i < n; i++)
        {
            vector<int> temp = find(nums[i]);

            for(auto factor : temp)
            {
                m[factor].push_back(i);
            }
        }
        int jump=0;
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        int jumps=0;

        while(!q.empty())
        {
            int temp=q.size();

            while(temp--)
            {
                int tp=q.front();
                q.pop();
                if(tp==n-1) return jumps;

                if(tp>0 && !vis[tp-1]){
                    vis[tp-1]=1;
                    q.push(tp-1);
                }

                if(tp<n-1 && !vis[tp+1]){
                    vis[tp+1]=1;
                    q.push(tp+1);
                }

                if(m.count(nums[tp]))
                {
                    for(auto j:m[nums[tp]])
                    {
                        if(!vis[j])
                        {
                            vis[j]=1;
                            q.push(j);
                        }
                    }
                    m[nums[tp]].clear();
                }
            }
            jumps++;
        }

        return jumps;

    }
};