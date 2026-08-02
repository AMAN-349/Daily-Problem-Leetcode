class Solution {
public:

    int dp[501][501][2];

    int find(int i, int j, bool turn, vector<int>& nums) {
        if (i > j)
            return 0;

        if(dp[i][j][turn]!=-1)
        {
            return dp[i][j][turn];
        }

        if (turn) {
            return dp[i][j][turn]=max(
                nums[i] + find(i + 1, j, false, nums),
                nums[j] + find(i, j - 1, false, nums)
            );
        } else {
            return dp[i][j][turn]=min(
                find(i + 1, j, true, nums),
                find(i, j - 1, true, nums)
            );
        }
    }

    bool stoneGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int total = accumulate(nums.begin(), nums.end(), 0);
        int alice = find(0, nums.size() - 1, true, nums);
        int bob = total - alice;
        return alice >= bob;
    }
};