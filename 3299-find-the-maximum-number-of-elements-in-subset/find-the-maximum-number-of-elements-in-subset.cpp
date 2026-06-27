class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> m;
        unordered_map<int,int> vis;
        for(auto i:nums)
        {
            m[i]++;
        }
        sort(nums.begin(),nums.end());
        if(m[1]%2==0)
        {
            m[1]--;
        }
        int res=max(1,m[1]);
        for(int i=0;i<n;i++)
        {
            if(vis[nums[i]] || nums[i]==1)
            {
                continue;
            }
            long long curr=nums[i];
            int ans=1;
            int temp;

            while(m[curr]>=1)
            {
                temp=sqrt(curr);
                if(temp*temp!=curr) break;

                if(temp==1) break;

                if(m[temp]>=2)
                {
                    ans+=2;
                    curr=temp;
                }
                else{
                    break;
                }
            }
            res=max(ans,res);
            vis[nums[i]]=1;
        }
        return res;
    }
};