class Solution {
public:

    int findmin(vector<vector<int>>& v)
{
    int ans=INT_MAX;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        ans=min(ans,v[i][0]);
    }
    return ans;
}

int findmax(vector<vector<int>>& v)
{
    int ans=INT_MIN;
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        ans=max(ans,v[i][n-1]);
    }
    return ans;
}

int count(vector<vector<int>>& v,int m)
{
    int ans=0;
    for(auto i:v)
    {
        ans+=upper_bound(i.begin(),i.end(),m)-i.begin();
    }
    return ans;
}


    int kthSmallest(vector<vector<int>>& v, int k) {
        int l=findmin(v);
    int r=findmax(v);
    while(l<=r)
    {
        int m=(l+r)/2;
        int temp=count(v,m);
        if(temp<k)
        {
            l=m+1;
        }
        else{
            if(count(v,m-1)<k)
            {
                return m;
            }
            else{
                r=m-1;
            }
        }
        
    }
    return -1;
    }
};