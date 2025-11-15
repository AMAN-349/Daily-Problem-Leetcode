class Solution {
public:

    vector<int> bit;
    int N;
    int sum(int i)
    {
        int ans=0;
        for(;i>0;i-=(i&-i))
        {
            ans+=bit[i];
        }
        return ans;
    }

    void update(int i,int x)
    {
        for(;i<N;i+=(i&-i))
        {
            bit[i]+=x;
        }
    }

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        N=n+5;
        bit.resize(N,0);
        for(int i=0;i<n;i++)
        {
            if(nums[i]==target)
            {
                nums[i]=1;
            }
            else{
                nums[i]=-1;
            }
        }
        for(int i=1;i<n;i++)
        {
            nums[i]+=nums[i-1];
        }
        long long ans=0;
        map<int,int> m;
        for(auto i:nums)
        {
            m[i];
        }
        m[0];
        int cnt=1;
        for(auto& i:m)
        {
            i.second=cnt++;
        }
        update(m[0],1);
        for(int i=0;i<n;i++)
        {
            int pos=m[nums[i]];
            ans+=sum(pos-1);
            update(pos,1);
        }
        return ans;
    }
};
