class Solution {
public:  

    static bool cmp(const pair<int,int>& a, const pair<int,int>& b)
    {
        if(a.second==b.second)
        {
            return a.first>b.first;
        }
        return a.second>b.second;

    }

    int find(vector<int>& nums,int l,int r,int x)
    {
        map<int,int> m;
        for(int i=l;i<=r;i++)
        {
            m[nums[i]]++;
        }
        vector<pair<int,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        int ans=0;
        int sz=min((int)v.size()-1,x-1);
        for(int i=0;i<=sz;i++)
        {
            cout<<v[i].first;
            cout<<endl;
            ans+=v[i].first*v[i].second;
        }
        return ans;
    }

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<=n-k;i++)
        {
            ans.push_back(find(nums,i,i+k-1,x));
        }
        return ans;
    }
};