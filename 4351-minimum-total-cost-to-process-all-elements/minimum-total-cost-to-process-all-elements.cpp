class Solution {
public:
    const long long MOD = 1e9 + 7;
    const long long INV2 = 500000004;
    int minimumCost(vector<int>& nums, int k) {
        int n=nums.size();
        long long cost=0;
        long long pwr=k;
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>pwr)
            {
                // cout<<" pwr"<<pwr;
                int diff=nums[i]-pwr;
                int steps=diff/k;
                if(diff%k!=0)
                {
                    steps++;
                }

                long long psum = (1LL * cost % MOD) * ((cost + 1) % MOD) % MOD;
                psum = psum * INV2 % MOD;

                cost += steps;

                long long ssum = (1LL * cost % MOD) * ((cost + 1) % MOD) % MOD;
                ssum = ssum * INV2 % MOD;
                ans=(ans+ssum-psum)%MOD;
                pwr+=(steps*k);
            }
            cout<<pwr<<" ";
            pwr-=nums[i];
        }
        return ans;
    }
};