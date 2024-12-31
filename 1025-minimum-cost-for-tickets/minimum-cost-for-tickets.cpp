#include <vector>
#include <algorithm>

class Solution {
public:

    int find(vector<int>& days, vector<int>& costs, int i, vector<int>& memo)
    {
        if (i >= days.size()) {
            // Base case: no more days to consider, cost is 0
            return 0;
        }

        if (memo[i] != -1) {
            // Return memoized result if available
            return memo[i];
        }

        int ans1, ans2, ans3;

        // Option 1: Use a 1-day pass
        ans1 = costs[0] + find(days, costs, i + 1, memo);

        // Option 2: Use a 7-day pass
        int j = i;
        while (j < days.size() && days[j] < days[i] + 7) {
            j++;
        }
        ans2 = costs[1] + find(days, costs, j, memo);

        // Option 3: Use a 30-day pass
        j = i;
        while (j < days.size() && days[j] < days[i] + 30) {
            j++;
        }
        ans3 = costs[2] + find(days, costs, j, memo);

        memo[i] = min(ans1, min(ans2, ans3));

        return memo[i];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i = 0; // Start from the first day
        vector<int> memo(days.size(), -1);
        return find(days, costs, i, memo);
    }
};
