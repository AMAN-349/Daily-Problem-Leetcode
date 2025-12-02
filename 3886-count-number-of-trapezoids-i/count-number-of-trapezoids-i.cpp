class Solution {
public:

    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        return a.second>b.second;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        long long mod=1e9+7;
        map<int,int> m;
        for(auto i:points)
        {
            int x=i[0];
            int y=i[1];
            m[y]++;
        }
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        long long ans=0;
        vector<long long> res;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].second<2)
            {
                break;
            }
            long long x = v[i].second;
            long long curr = ( (x * (x - 1)) % mod ) * 1LL / 2;
            curr=curr%mod;
            res.push_back(curr);
        }
        for(int i=1;i<res.size();i++)
        {
            res[i]+=res[i-1];
        }
        int k=res.size();
        for(int i=0;i<k;i++)
        {
            long long curr = (i > 0) ? (res[i] - res[i-1] + mod) % mod : res[i];
            long long rem = (res[k-1] - res[i] + mod) % mod;
            ans+=(rem*curr);
            ans%=mod;
        }
        return ans;
    }
};