class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size();
    if(n<3)
    {
        return 0;
    }
    vector<int> pre(n,0);
    vector<int> suf(n,0);
    pre[0]=v[0];
    suf[n-1]=v[n-1];
    for(int i=1;i<n;i++)
    {
        pre[i]=max(pre[i-1],v[i]);
    }
    for(int i=n-2;i>=0;i--)
    {
        suf[i]=max(suf[i+1],v[i]);
    }
    int ans=0;
    int mini=0;
    for(int i=0;i<n;i++)
    {
        mini=min(pre[i],suf[i]);
        if(v[i]<=mini)
        {
            ans+=mini-v[i];
        }
    }
    return ans;

    }
};