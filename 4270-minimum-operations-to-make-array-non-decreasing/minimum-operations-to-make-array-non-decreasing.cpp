class Solution {
public:

    int find(int start,int end,int target,vector<int>& nums)
    {
        if (start > end) return 0;
        vector<int> v;
        for(int i=start;i<=end;i++)
        {
            v.push_back(nums[i]);
        }
        int mini=*min_element(v.begin(),v.end());
        int diff=(target-mini);
        return diff;
    }

    long long minOperations(vector<int>& nums) {
        int n=nums.size();
        long long res=0LL;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                int temp=nums[i-1];
                int j=i;
                while(j<n-1 && nums[j]<nums[j+1] && nums[j+1]<temp)
                {
                    j++;
                }
                res+=(find(i,j,temp,nums)*1LL);
                i=j;
            }
        }
        return res;
    }
};