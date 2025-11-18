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

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        bit.resize(105,0);
        N=105;
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                cnt++;
            }
            else
            {
                update(nums[i],1);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                ans.push_back(0);
            }
            else{
                ans.push_back(sum(nums[i]-1)+cnt);
            }
        }
        return ans;
    }
};