class Solution {
public:

    void find(int n,vector<int>& ans)
    {
        int j=31;
        while(n>0)
        {
            int bit=(n&1);
            ans[j]+=bit;
            n>>=1;
            j--;
        }
    }
    int largestCombination(vector<int>& candidates) {
        vector<int> ans(32,0);
        for(auto i:candidates)
        {
            find(i,ans);
        }
        int res=0;
        for(int i=0;i<32;i++)
        {
            res=max(res,ans[i]);
        }
        return res;
    }
};