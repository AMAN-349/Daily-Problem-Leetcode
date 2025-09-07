class Solution {
public:

    void find(int n, int k, vector<int>& div, vector<int>& ans, int& res) {
        if (n == 1) {
            if (div.size() <= k) {
                vector<int> temp = div;
                while (temp.size() < k) temp.push_back(1);

                int mini = *min_element(temp.begin(), temp.end());
                int maxi = *max_element(temp.begin(), temp.end());

                if ((maxi - mini) < res) {
                    res = maxi - mini;
                    ans = temp;
                }
            }
            return;
        }

        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                div.push_back(i);
                find(n / i, k, div, ans, res);
                div.pop_back();
            }
        }
    }

    vector<int> minDifference(int n, int k) {
        vector<int> ans;
        vector<int> div;
        int res = INT_MAX;
        find(n, k, div, ans, res);
        return ans;
    }
};
