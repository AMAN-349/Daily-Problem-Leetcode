class Solution {
public:
    int n;
    vector<int> dp;

    int maxResult(vector<int>& nums, int k) {
        n=nums.size();
        priority_queue<pair<int,int>> pq;
        dp.resize(n,0);
        dp[n-1] = nums[n-1];
        pq.push({nums[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            while(!pq.empty() && pq.top().second>i+k)
            {
                pq.pop();
            }
            dp[i]=nums[i]+pq.top().first;
            pq.push({dp[i],i});
        }
        return dp[0];
    }
};