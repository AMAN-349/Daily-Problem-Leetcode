class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;

        vector<long long> power(n);
        power[0] = 1;
        for (int i = 1; i < n; i++) {
            power[i] = (power[i-1] * 2) % MOD;
        }

        for (int i = 0; i < n; i++) {
            ans = (ans + nums[i] * (power[i] - 1)) % MOD;
            ans = (ans - nums[i] * (power[n - i - 1] - 1)) % MOD;
        }

        if (ans < 0) {
            ans += MOD;
        }

        return static_cast<int>(ans);
    }
};





// class Solution {
// public:
//     int sumSubseqWidths(vector<int>& nums) {
//         vector<int> v=nums;
//         sort(v.begin(),v.end());
//         int ans=0;
//         int nsum=0;
//         int n=nums.size();
//         for(int i=0;i<v.size();i++)
//         {
//             nsum+=(v[i]*(pow(2,n-(i+1))-1));
//         }
//         nsum%=1000000007;
//         int psum=0;
//         for(int i=0;i<v.size();i++)
//         {
//             psum+=(v[i]*(pow(2,i)-1));
//         }
//         psum%=1000000007;
//         ans=psum-nsum;
//         return ans;
//     }
// };