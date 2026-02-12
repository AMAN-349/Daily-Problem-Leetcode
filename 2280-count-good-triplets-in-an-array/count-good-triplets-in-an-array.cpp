class Solution {
public:
    vector<int> segtree;
    using ll = long long;

    int query(int start,int end,int i,int l,int r)
    {
        if(start>r || end<l)
        {
            return 0;
        }
        if(l>=start && r<=end)
        {
            return segtree[i];
        }
        int m=(l+r)/2;
        int left=query(start,end,2*i+1,l,m);
        int right=query(start,end,2*i+2,m+1,r);
        return left+right;
    }

    void update(int i,int l,int r,int idx)
    {
        if(l==r)
        {
            segtree[i]=1;
            return;
        }
        int m=(l+r)/2;
        if(idx>m)
        {
            update(2*i+2,m+1,r,idx);
        }
        else{
            update(2*i+1,l,m,idx);
        }
        segtree[i]=segtree[2*i+1]+segtree[2*i+2];
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        segtree.resize(4*n,0);
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            m[nums2[i]]=i;
        }
        ll ans=0;
        update(0,0,n-1,m[nums1[0]]);
        for(int i=1;i<n-1;i++)
        {
            int idx=m[nums1[i]];
            ll leftcommoncount=query(0,idx,0,0,n-1);
            ll leftuncommon=i-leftcommoncount;
            ll rightidxcount=n-1-idx;
            ll rightcommoncount=rightidxcount-leftuncommon;
            ans+=(1LL*leftcommoncount*rightcommoncount);
            update(0,0,n-1,m[nums1[i]]);
        }
        return ans;
    }
};