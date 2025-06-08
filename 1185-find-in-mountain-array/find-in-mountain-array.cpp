/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int bsAsc(MountainArray &arr, int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;
            int val = arr.get(m);
            if (val == target) return m;
            else if (val < target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

    int bsDesc(MountainArray &arr, int l, int r, int target) {
        while (l <= r) {
            int m = (l + r) / 2;
            int val = arr.get(m);
            if (val == target) return m;
            else if (val > target) l = m + 1;
            else r = m - 1;
        }
        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int l = 0, r = n - 1;
        int peak = -1;

        while (l <= r) {
            int m = (l + r) / 2;
            int mid = mountainArr.get(m);
            int left = (m == 0) ? INT_MIN : mountainArr.get(m - 1);
            int right = (m == n - 1) ? INT_MIN : mountainArr.get(m + 1);

            if (mid > left && mid > right) {
                peak = m;
                break;
            } else if (mid > left) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        int idx = bsAsc(mountainArr, 0, peak, target);
        if (idx != -1) return idx;

        return bsDesc(mountainArr, peak + 1, n - 1, target);
    }
};
