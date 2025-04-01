class Solution {
public:
    vector<long long> dp;
    long long find(vector<vector<int>>& questions, int i, int n) {
        if (i >= n) {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }

        long long ans1 = 0;
        long long ans2 = 0;

        ans1 = questions[i][0] + find(questions, i + questions[i][1]+1, n);

        ans2 = find(questions, i + 1, n);

        return dp[i]=max(ans1, ans2);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        dp.resize(n+1,-1);
        int i = 0;
        return find(questions, i, n);
    }
};
