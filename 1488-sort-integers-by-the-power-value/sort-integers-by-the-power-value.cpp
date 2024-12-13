class Solution {
public:

    static bool tmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.second==b.second) return a.first<b.first;
        return a.second<b.second;
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int,int>> v;
        for(int i=lo;i<=hi;i++)
        {
            int cnt=0;
            int x=i;
            while(x!=1)
            {
                if(x%2==0)
                {
                    x=x/2;
                }
                else{
                    x=(3*x)+1;
                }
                cnt++;
            }
            v.push_back({i,cnt});
        }
        sort(v.begin(),v.end(),tmp);
        return v[k-1].first;
    }
};