class Solution {
public:
    int n;

    int stoneGameVIII(vector<int>& stones) {
        n = stones.size();
        for(int i = 1; i < n; i++)
            stones[i] += stones[i - 1];

        int dp=stones[n-1];
        int ans=0;
        for(int i=n-2;i>0;i--)
        {
            dp=max(dp,stones[i]-dp);
        }

        return dp;
    }
};