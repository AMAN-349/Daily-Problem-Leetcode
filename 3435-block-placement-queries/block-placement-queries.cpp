class Solution {
public:
    vector<int> segTree;

    int query(int l,int r,int i,int start,int end)
    {
        if(start>r || end<l)
        {
            return 0;
        }
        if(start>=l && end<=r)
        {
            return segTree[i];
        }
        int mid = (start + end) / 2;
        return max(query(l,r,2*i+1,start,mid),query(l,r,2*i+2,mid+1,end));
    }

    void update(int idx,int val,int i,int start,int end)
    {
        if(start==end)
        {
            segTree[i] = val;
            return;
        }
        int mid=(start+end)/2;
        if(mid>=idx)
        {
            update(idx,val,2*i+1,start,mid);
        }
        else{
            update(idx,val,2*i+2,mid+1,end);
        }
        segTree[i]=max(segTree[2*i+1],segTree[2*i+2]);
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int n=50000;
        segTree.resize(4*n,0);
        set<int> s;
        s.insert(0);
        vector<bool> res;

        for(auto i:queries)
        {
            int typ=i[0];
            if(typ==1)
            {
                int idx=i[1];
                auto upr=s.upper_bound(idx);
                int right=upr!=s.end()?*(upr):-1;
                int left=upr!=s.begin()?*prev(upr):-1;
                update(idx,idx-left,0,0,n-1);
                update(right,right-idx,0,0,n-1);
                s.insert(idx);
            }
            else{
                int idx=i[1];
                int sz=i[2];
                auto upr=s.upper_bound(idx);
                int ind=*(prev(upr));

                int ans=query(0,ind,0,0,n-1);
                ans=max(ans,idx-ind);
                if(ans>=sz)
                {
                    res.push_back(true);
                }
                else{
                    res.push_back(false);
                }
            }
        }

        return res;
    }
};