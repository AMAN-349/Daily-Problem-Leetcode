class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int ans=0;
        for (int i = 0; i < n; i++) {
            int first=intervals[i][0];
            int second=intervals[i][1];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (first >= intervals[j][0] &&
                    second <= intervals[j][1] &&
                    (first != intervals[j][0] || second != intervals[j][1])) {
                    ans++;
                    break;
                }
            }
        }
        return n - ans;
    }
};