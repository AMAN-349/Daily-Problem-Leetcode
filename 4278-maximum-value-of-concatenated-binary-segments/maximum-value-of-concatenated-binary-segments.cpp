class Solution {
public:

    long long mod=1e9+7;

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<int> v;
        int n=nums1.size();

        for(int i=0;i<n;i++)
        {
            v.push_back(i);
        }

        sort(v.begin(), v.end(),
        [&](int a, int b)
        {
            int pos0_at_a=nums0[a]==0?INT_MAX:nums1[a]+1;
            int pos0_at_b=nums0[b]==0?INT_MAX:nums1[b]+1;

            if(pos0_at_a==pos0_at_b)
            {
                return nums0[a]<nums0[b];
            }

            return pos0_at_a>pos0_at_b;
        });

        long long ans = 0;

        for (int i : v) {
            for (int j = 0; j < nums1[i]; j++) ans = (ans * 2 + 1) % mod;
            for (int j = 0; j < nums0[i]; j++) ans = (ans * 2) % mod;
        }
        return ans;
    }
};