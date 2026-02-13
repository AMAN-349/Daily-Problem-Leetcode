class Solution {
public:

    //here we do lazy propagation also
    vector<int> maxseg;
    vector<int> minseg;
    vector<int> lazy;

    void propagate(int i,int l,int r)
    {
        if(lazy[i]!=0)
        {
            int val=lazy[i];
            minseg[i]+=val;
            maxseg[i]+=val;
            if(l!=r){
                lazy[2*i+1]+=val;
                lazy[2*i+2]+=val;
            }
            lazy[i]=0;
        }
    }

    void updaterange(int start,int end,int i,int l,int r,int val)
    {
        propagate(i,l,r);
        if(l>end || r<start)
        {
            return;
        }
        if(l>=start && r<=end)
        {
            lazy[i]+=val;
            propagate(i,l,r);
            return;
        }
        int m=(l+r)/2;
        updaterange(start,end,2*i+1,l,m,val);
        updaterange(start,end,2*i+2,m+1,r,val);
        maxseg[i]=max(maxseg[2*i+1],maxseg[2*i+2]);
        minseg[i]=min(minseg[2*i+1],minseg[2*i+2]);
    }

    int findleftzero(int i,int l,int r)
    {
        propagate(i,l,r);
        if(minseg[i]>0 || maxseg[i]<0)
        {
            return -1;
        }
        if(l==r)
        {
            return l;
        }
        int m=(l+r)/2;
        int left=findleftzero(2*i+1,l,m);
        if(left!=-1)
        {
            return left;
        }
        return findleftzero(2*i+2,m+1,r);
    }

    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        maxseg.resize(4*n,0);
        minseg.resize(4*n,0);  
        lazy.resize(4*n,0);
        //build(0,0,n-1,nums);

        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int sum=(nums[i]%2==0)?1:-1;
            int prev=-1;
            if(m.count(nums[i]))
            {
                prev=m[nums[i]];
            }
            if(prev!=-1)
            {
                updaterange(0,prev,0,0,n-1,-sum);
            }
            updaterange(0,i,0,0,n-1,sum);
            int temp=findleftzero(0,0,n-1);
            if(temp!=-1)
            {
                ans=max(ans,i-temp+1);
            }
            m[nums[i]]=i;
        }
        return ans;
    }
};