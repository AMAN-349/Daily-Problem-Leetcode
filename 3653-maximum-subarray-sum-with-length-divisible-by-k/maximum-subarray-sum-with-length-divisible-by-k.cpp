class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        long long ans=LONG_MIN;
        for(int i=0;i<k;i++)
        {
            int j=i;
            long long temp=0;
            while(j<n)
            {
                if(j + k-1 <= n - 1)
                {
                    long long temp2 = prefix[j + k-1] - (j > 0 ? prefix[j - 1] : 0);
                    temp=max(temp2,temp+temp2);
                    ans=max(ans,temp);
                    j+=k;
                }
                else{
                    break;
                }

            }
        }
        return ans;
    }
};