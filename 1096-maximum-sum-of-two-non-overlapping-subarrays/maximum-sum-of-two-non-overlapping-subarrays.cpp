class Solution {
public:
    int find(int i, int j, vector<int>& pre, int len) {
        if ((j - i + 1) < len) return 0;

        int ans = pre[i + len - 1] - (i > 0 ? pre[i - 1] : 0);
        int res = ans;

        while (i + len <= j) {
            ans = pre[i + len] - pre[i];
            res = max(res, ans);
            i++;
        }

        return res;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n = nums.size();

        // Step 1: Compute prefix sum
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        int mini = min(firstLen, secondLen);
        int maxi = max(firstLen, secondLen);
        int res = 0;

        for (int i = 0; i + mini - 1 < n; i++) {
            int j = i + mini - 1;

            int ans = pre[j] - (i > 0 ? pre[i - 1] : 0);

            int temp1 = find(0, i - 1, pre, maxi);       
            int temp2 = find(j + 1, n - 1, pre, maxi);   

            res = max(res, ans + max(temp1, temp2));
        }

        return res;
    }
};
