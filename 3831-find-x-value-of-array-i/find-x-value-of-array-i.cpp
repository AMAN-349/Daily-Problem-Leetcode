class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> ans;
        vector<vector<long long>> dp(n,vector<long long>(k,0));
        int temp=nums[0];
        dp[0][temp%k]+=1;

        for(int i=1;i<n;i++)
        {
            int curr=nums[i]%k;
            vector<long long>& temp=dp[i-1];
            dp[i][nums[i]%k]++;
            for(int j = 0; j < k; j++)
            {
                int cnt = temp[j];

                if(cnt==0)
                    continue;

                dp[i][(j*(nums[i] % k))%k] += cnt;
            }
        }
        for(int i=0;i<k;i++)
        {
            long long curr=0;
            for(int j=0;j<n;j++)
            {
                curr+=dp[j][i];
            }
            ans.push_back(curr);
        }
        return ans;
    }
};