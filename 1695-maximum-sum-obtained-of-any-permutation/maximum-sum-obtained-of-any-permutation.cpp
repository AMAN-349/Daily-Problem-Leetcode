class Solution {
public:
    long long mod=1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();

        vector<int> temp(n+1,0);

        map<int,int> mp;

        for(auto i:requests)
        {
            temp[i[0]]++;
            if(i[0]<n-1)
            temp[i[1]+1]--;
        }

        int sum=0;
        for(int i=0;i<temp.size();i++)
        {
            sum+=temp[i];
            temp[i]=sum;
        }

        vector<pair<int,int>> v;

        for(int i=0;i<n;i++)
        {
            v.push_back({temp[i],i});
        }

        sort(v.begin(),v.end(),greater<pair<int,int>>());
        sort(nums.begin(),nums.end());

        int pt=n-1;

        vector<long long> ans(n,-1);

        for(auto i:v)
        {
            ans[i.second]=nums[pt];
            pt--;
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]==-1)
            {
                ans[i]=nums[pt];
                pt--;
            }
        }
        for(auto i:ans)
        {
            cout<<i<<" ";
        }

        for(int i=1;i<n;i++)
        {
            ans[i]+=ans[i-1];
        }


        long long res=0;

        for(auto i:requests)
        {
            int st=i[0];
            int end=i[1];

            res = (res+ans[end] - (st > 0 ? ans[st - 1] : 0))%mod;
        }

        return res;
    }
};