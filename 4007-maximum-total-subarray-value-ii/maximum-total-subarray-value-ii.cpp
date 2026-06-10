class Solution {
public:

    vector<int> segTree1;
    vector<int> segTree2;

    void buildsegTree1(int i,int l,int r,vector<int>& nums)
    {
        if(l==r)
        {
            segTree1[i]=nums[l];
            return;
        }
        int m=(l+r)/2;
        buildsegTree1(2*i+1,l,m,nums);
        buildsegTree1(2*i+2,m+1,r,nums);
        segTree1[i]=max(segTree1[2*i+1],segTree1[2*i+2]);
    }

    void buildsegTree2(int i,int l,int r,vector<int>& nums)
    {
        if(l==r)
        {
            segTree2[i]=nums[l];
            return;
        }
        int m=(l+r)/2;
        buildsegTree2(2*i+1,l,m,nums);
        buildsegTree2(2*i+2,m+1,r,nums);
        segTree2[i]=min(segTree2[2*i+1],segTree2[2*i+2]);
    }

    int query1(int i,int l,int r,int start,int end)
    {
        if(end<l || start>r)
        {
            return INT_MIN;
        }
        if(start<=l && end>=r)
        {
            return segTree1[i];
        }
        int m=(l+r)/2;
        return max(query1(2*i+1,l,m,start,end),query1(2*i+2,m+1,r,start,end));
    }

    int query2(int i,int l,int r,int start,int end)
    {
        if(end<l || start>r)
        {
            return INT_MAX;
        }
        if(start<=l && end>=r)
        {
            return segTree2[i];
        }
        int m=(l+r)/2;
        return min(query2(2*i+1,l,m,start,end),query2(2*i+2,m+1,r,start,end));
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();
        segTree1.resize(4*n,0);
        segTree2.resize(4*n,0);
        buildsegTree1(0,0,n-1,nums);
        buildsegTree2(0,0,n-1,nums);

        priority_queue<pair<int,pair<int,int>>> pq;

        for(int i=0;i<n;i++)
        {
            int maxi=query1(0,0,n-1,i,n-1);
            int mini=query2(0,0,n-1,i,n-1);
            pq.push({maxi-mini,{i,n-1}});
        }
        long long ans=0;

        while(k-- && !pq.empty())
        {
            auto temp = pq.top();
            pq.pop();

            cout << temp.first << " ";
            ans += 1LL*temp.first; 

            int l = temp.second.first;
            int r = temp.second.second;

            if (l < r) {
                int maxi = query1(0,0,n-1,l,r-1);
                int mini = query2(0,0,n-1,l,r-1);
                pq.push({maxi-mini,{l,r-1}});
            }
        }

        return ans;
    }
};