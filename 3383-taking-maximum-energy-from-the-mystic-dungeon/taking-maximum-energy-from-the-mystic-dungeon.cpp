class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int n=energy.size();
        int ans=INT_MIN;
        vector<int> dp(n+1);
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=energy[i];
            if((i+k)<n)
            {
                dp[i]+=dp[i+k];
            }
            ans=max(ans,dp[i]);
        }
        for(auto i:dp)
        {
            cout<<i<<" ";
        }
        return ans;
    }
};