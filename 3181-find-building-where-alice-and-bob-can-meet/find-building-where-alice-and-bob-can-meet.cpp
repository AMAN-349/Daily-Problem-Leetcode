class Solution {
public:
    int n;
    vector<int> segtree;

    void build(int i,int l,int r,vector<int>& heights)
    {
        if(l==r)
        {
            segtree[i]=l;
            return;
        }
        int m=(l+r)/2;
        build(2*i+1,l,m,heights);
        build(2*i+2,m+1,r,heights);
        int leftidx=segtree[2*i+1];
        int rightidx=segtree[2*i+2];
        if(heights[leftidx]>=heights[rightidx])
        {
            segtree[i]=leftidx;
            return;
        }
        segtree[i]=rightidx;
    }

    int query(int start,int end,int i,int l,int r,vector<int>& heights)
    {
        if(start>r || end<l)
        {
            return -1;
        }
        if(l>=start && r<=end)
        {
            return segtree[i];
        }
        int m=(l+r)/2;
        int leftidx=query(start,end,2*i+1,l,m,heights);
        int rightidx=query(start,end,2*i+2,m+1,r,heights);

        if(leftidx==-1)
        {
            return rightidx;
        }
        if(rightidx==-1)
        {
            return leftidx;
        }
        if(heights[leftidx]>=heights[rightidx])
        {
            return leftidx;
        }
        return rightidx;
    }

    int binsearch(int a,int b,int start,int end,vector<int>& heights)
    {
        int l=start;
        int r=end;
        int ans=-1;
        while(l<=r)
        {
            int m=l+(r-l)/2;
            int temp=query(l,m,0,0,n-1,heights);
            if(temp!=-1 && heights[temp]>a && heights[temp]>b)
            {
                ans=temp;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;

    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n=heights.size();
        segtree.resize(4*n,0);
        build(0,0,n-1,heights);
        vector<int> ans;
        for (auto &q : queries) {
            int i = q[0], j = q[1];

            if (i == j) {
                ans.push_back(i);
                continue;
            }

            int x = min(i, j);
            int y = max(i, j);

            if (heights[y] > heights[x]) {
                ans.push_back(y);
                continue;
            }

            int temp = query(y + 1, n - 1, 0, 0, n - 1, heights);
            if (temp == -1 || heights[temp] <= heights[x]) {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(binsearch(heights[x], heights[y], y + 1, n - 1, heights));
        }

        return ans;
    }
};