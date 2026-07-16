class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n,0);
        prefix[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],nums[i]);
        }

        for(int i=0;i<n;i++)
        {
            prefix[i]=__gcd(prefix[i],nums[i]);
        }
        sort(prefix.begin(),prefix.end());

        for(auto i:prefix)
        {
            cout<<i<<" ";
        }

        long long ans=0;

        for(int i=0;i<n/2;i++)
        {
            ans+=__gcd(prefix[i],prefix[n-1-i]);
        }

        return ans;
    }
};