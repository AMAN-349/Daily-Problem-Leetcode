class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        int mod=1e9+7;
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        hFences.insert(hFences.begin(),1);
        hFences.push_back(m);

        vFences.insert(vFences.begin(),1);
        vFences.push_back(n);

        set<int> ans;

        for(int i=0;i<hFences.size();i++)
        {
            for(int j=i+1;j<hFences.size();j++)
            {
                ans.insert(hFences[j]-hFences[i]);
            }
        }
        int res=0;
        for(int i=0;i<vFences.size();i++)
        {
            for(int j=i+1;j<vFences.size();j++)
            {
                int temp=vFences[j]-vFences[i];
                if(ans.find(temp)!=ans.end())
                {
                    res=max(res,temp);
                }
            }
        }
        if(res==0)
        {
            return -1;
        }
        long long t = (1LL * res * res) % mod;
        return t;
    }
};