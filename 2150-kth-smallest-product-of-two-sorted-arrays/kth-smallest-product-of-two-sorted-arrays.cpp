class Solution {
public:

    long long countpositive(int x, vector<int>& nums2, long long mid) {
        int l = 0, r = nums2.size() - 1;
        long long res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (1LL * x * nums2[m] <= mid) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return l;
    }

    long long countnegative(int x, vector<int>& nums2, long long mid) {
        int l = 0, r = nums2.size() - 1;
        long long res = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (1LL * x * nums2[m] <= mid) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return nums2.size() - l;
    }

    long long count(vector<int>& nums1, vector<int>& nums2, long long mid) {
        long long cnt = 0;
        for (auto x : nums1) {
            if (x == 0) {
                if (mid >= 0) cnt += nums2.size();
            } else if (x > 0) {
                cnt += countpositive(x, nums2, mid);
            } else {
                cnt += countnegative(x, nums2, mid);
            }
        }
        return cnt;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long mini = -1e10, maxi = 1e10, ans = 0;
        while (mini <= maxi) {
            long long m = mini + (maxi - mini) / 2;
            if (count(nums1, nums2, m) < k) {
                mini = m + 1;
            } else {
                ans = m;
                maxi = m - 1;
            }
        }
        return ans;
    }
};
