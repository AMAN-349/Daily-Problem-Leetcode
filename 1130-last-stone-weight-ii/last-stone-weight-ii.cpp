class Solution {
public:
    vector<vector<int>> ans;
    int find(int i, vector<int>& stones, int target)
    {
        if (target < 0) return -1e9;
        if (i < 0) return 0;
        if(ans[i][target]!=-1)
        {
            return ans[i][target];
        }

        int take = stones[i] + find(i-1, stones, target - stones[i]);
        int notTake = find(i-1, stones, target);

        return ans[i][target]=max(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        ans.resize(n,vector<int>(target+1,-1));
        int best = find(stones.size() - 1, stones, target);
        return sum - 2 * best;
    }
};
