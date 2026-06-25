class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        if(res.size()==0)
        {
            return n-1;
        }
        res.push_back({1,0});
        sort(res.begin(),res.end());

        cout<<endl;

        for(int i=1;i<res.size();i++)
        {
            int dist=res[i][0]-res[i-1][0];
            int ht1=res[i-1][1];
            int ht2=res[i][1];

            if(ht2>(ht1+dist))
            {
                res[i][1]=ht1+dist;
            }
        }

        for(auto i:res)
        {
            cout<<i[1]<<" ";
        }

        cout<<endl;

        for(int i=res.size()-2;i>=0;i--)
        {
            int dist=res[i+1][0]-res[i][0];
            int ht1=res[i+1][1];
            int ht2=res[i][1];

            if(ht2>ht1+dist)
            {
                res[i][1]=ht1+dist;
            }
        }
        int ans = 0;

        for(auto &x : res)
            ans = max(ans, x[1]);

        for(int i=1;i<res.size();i++)
        {
            int lh = res[i-1][1];
            int rh = res[i][1];
            int dist = res[i][0] - res[i-1][0];

            ans = max(ans, (lh + rh + dist) / 2);
        }

        ans = max(ans,res.back()[1] + (n - res.back()[0]));

        return ans;
    }
};