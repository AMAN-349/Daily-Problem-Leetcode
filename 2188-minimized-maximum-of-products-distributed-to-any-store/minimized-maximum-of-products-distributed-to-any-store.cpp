class Solution {
public:

    int find(int x,int n,vector<int> quan)
    {
        int j=0;
        int rem=quan[j];
        for(int i=0;i<n;i++)
        {
            if(rem<=x)
            {
                j++;
                if(j==quan.size())
                {
                    return true;
                }
                else{
                    rem=quan[j];
                }
            }
            else{
                rem-=x;
            }
        }
        return false;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=0;
        int r=*max_element(quantities.begin(),quantities.end());
        while(l<r)
        {
            int mid=(l+r)/2;
            if(find(mid,n,quantities))
            {
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};